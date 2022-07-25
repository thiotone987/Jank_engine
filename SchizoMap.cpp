#include "SchizoMap.h"

// Identical to std::ranges::range
// Remove when Apple Clang adds std::ranges::range to the standard library
template<class T>
concept range = requires( T& t ) {
    std::ranges::begin(t);
    std::ranges::end(t);
};

SchizoMap::SchizoMap(std::initializer_list<Object*> il) {
    for (Object *obj : il) {
        add(obj);
    }
}

void SchizoMap::add(Object *obj) {
    const auto& obj_attr_map = obj->get_attr_map();

    this->objects.insert(obj);
    std::unordered_set<std::string> attr_names;
    for (auto const& attr : obj_attr_map) {
        attr_names.insert(attr.first);
    }
    objs_to_attr_names.insert(std::make_pair(obj, attr_names));

    for (const auto& [attr_name, attr_val] : obj_attr_map) {
        // This works even if there are no objects with that attribute and/or value yet,
        // because map's [] operator will create a (default-constructed) element if it doesn't exist.
        // Specifically:
        //  The [attr_name] access will create an empty map
        //  (mapping attribute values to the set of objects with that attribute value) if it doesn't exist yet.
        //  The [attr_val] access will create an empty unordered_set of object pointers if it doesn't exist yet.
        attr_metamap[attr_name][attr_val].insert(obj);
    }
}

void SchizoMap::remove(Object *obj) {
    // removes obj from attr_metamap
    this->objects.erase(obj);
    auto obj_attr_map = obj->get_attr_map();
    const auto& obj_attr_names = objs_to_attr_names[obj];
    for (const auto& attr_name : obj_attr_names) {
        const auto& attr_val = obj_attr_map[attr_name];
        std::unordered_set<Object*>& objs_with_attr = attr_metamap[attr_name][attr_val];
        objs_with_attr.erase(obj);
        if (objs_with_attr.empty()) {
            attr_metamap[attr_name].erase(attr_val);
        }
    }

    objs_to_attr_names.erase(obj);
}

std::unordered_set<Object*> SchizoMap::filter(const std::string& attr_name, const Object::attr_variant_t& attr_val) {
    return attr_metamap[attr_name][attr_val];
}

std::ostream& print_with_separator(std::ostream& ost, const range auto& container, const std::string& separator) {
    for (auto attr_name = container.begin(); attr_name != container.end(); attr_name++) {
        ost << *attr_name;
        if (std::next(attr_name) != container.end()) ost << separator;
    }
    return ost;
}

std::ostream& operator<<(std::ostream& ost, const SchizoMap& schizo_map) {
    ost << "Objects: " << std::endl;
    for (const auto& [obj, attr_names] : schizo_map.objs_to_attr_names) {
        ost << "\tObject at address " << obj << " has attributes: ";
        print_with_separator(std::cout, attr_names, ", ");
        ost << std::endl;
    }
    ost << "Attributes: " << std::endl;
    for (const auto& [attr_name, attr_vals_to_obj_sets] : schizo_map.attr_metamap) {
        ost << "\tValues for \"" << attr_name << "\" attribute: " << std::endl;
        for (const auto& [attr_val, objs_with_that_attr_val] : attr_vals_to_obj_sets) {
            ost << "\t\tThe following objects have this attribute with the value " << attr_val << ": " << std::endl;
            ost << "\t\t\t";
            print_with_separator(std::cout, objs_with_that_attr_val, ", ");
            ost << std::endl;
        }
    }
    ost << std::endl;
    return ost;
}
