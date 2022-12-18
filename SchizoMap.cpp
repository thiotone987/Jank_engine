#include "SchizoMap.h"
#include "Object.h"

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
    objects.insert(obj);
    for (const auto& [attr_name, attr_val] : obj->get_attr_map()) {
        attr_metamap[attr_name][attr_val].insert(obj);
        objs_to_attr_names[obj].insert(attr_name);
    }
}

void SchizoMap::remove(Object *obj) {
    objects.erase(obj);
    for (const auto& attr_name : objs_to_attr_names[obj]) {
        attr_metamap[attr_name][obj->get_attr_map()[attr_name]].erase(obj);
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
    ost << "Objects: \n";
    for (const auto& [obj, attr_names] : schizo_map.objs_to_attr_names) {
        ost << "\tObject at address " << obj << " has attributes: ";
        print_with_separator(std::cout, attr_names, ", ");
        ost << "\n";
    }
    ost << "Attributes: \n";
    for (const auto& [attr_name, attr_vals_to_obj_sets] : schizo_map.attr_metamap) {
        ost << "\tValues for \"" << attr_name << "\" attribute: " << std::endl;
        for (const auto& [attr_val, objs_with_that_attr_val] : attr_vals_to_obj_sets) {
            ost << "\t\tThe following objects have this attribute with the value " << attr_val << ": " << std::endl;
            ost << "\t\t\t";
            print_with_separator(std::cout, objs_with_that_attr_val, ", ");
            ost << "\n";
        }
    }
    ost << "\n";
    return ost;
}
