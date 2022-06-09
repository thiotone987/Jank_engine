//
// Created by Jacob Friedman on 6/6/22.
//

#include "SchizoMap.h"

void SchizoMap::add(Object* obj) {
    const auto& obj_attr_map = obj->get_attr_map();

    std::unordered_set<std::string> attr_names;
    for (auto const& attr : obj_attr_map) {
        attr_names.insert(attr.first);
    }
    objs_to_attr_names.insert(std::make_pair(obj, attr_names));

    for (const auto& attr : obj_attr_map) {
        const auto& attr_name = attr.first;
        const auto& attr_val = attr.second;

        if (attr_metamap.contains(attr_name)) {
            auto &objs_with_attr = attr_metamap[attr_name][attr_val];
            objs_with_attr.insert(obj);
        }
        else {
            std::unordered_map<Object::attr_val_t , std::unordered_set<Object*>, boost::hash<Object::attr_val_t>> new_attr_map;
            std::unordered_set<Object*> objs_with_attr;
            objs_with_attr.insert(obj);
            new_attr_map.insert(std::make_pair(attr_val, objs_with_attr));
            attr_metamap.insert(std::make_pair(attr_name, new_attr_map));
        }
    }
}

void SchizoMap::remove(Object* obj) {
    // remove from attr_metamap
    auto obj_attr_map = obj->get_attr_map();
    const auto& obj_attr_names = objs_to_attr_names[obj];
    for (const auto& attr_name : obj_attr_names) {
        const auto& attr_val = obj_attr_map[attr_name];
        std::unordered_set<Object*>& attr_obj_set = attr_metamap[attr_name][attr_val];
        attr_obj_set.erase(obj);
        if (attr_obj_set.empty()) {
            attr_metamap[attr_name].erase(attr_val);
        }
    }

    // remove from objs_to_attr_names
    objs_to_attr_names.erase(obj);
}

std::unordered_set<Object*> SchizoMap::filter(const std::string& attr_name, const Object::attr_val_t & attr_val) {
    return attr_metamap[attr_name][attr_val];
}

std::ostream& operator<<(std::ostream& ost, const SchizoMap& schizo_map) {
    ost << "Objects: " << std::endl;
    for (const auto& temp : schizo_map.objs_to_attr_names) {
        const auto& obj = temp.first;
        const auto& attr_names = temp.second;
        ost << "\tObject at address " << obj << " has attributes: ";
        for (const std::string& attr_name : attr_names) {
            ost << attr_name << ", ";
        }
        ost << std::endl;
    }
    ost << "Attributes: " << std::endl;
    for (const auto& temp : schizo_map.attr_metamap) {
        const auto& attr_name = temp.first;
        const auto& attr_vals_to_obj_sets = temp.second;
        ost << "\tValues for " << attr_name << " attribute: " << std::endl;
        for (const auto& temp2 : attr_vals_to_obj_sets) {
            const auto& attr_val = temp2.first;
            const auto& obj_set = temp2.second;
            ost << "\t\tThe following objects have this attribute with value " << attr_val << ": " << std::endl;
            ost << "\t\t\t";
            for (const auto& obj : obj_set) {
                ost << obj << ", ";
            }
            ost << std::endl;
        }
    }
    ost << std::endl;
    return ost;
}