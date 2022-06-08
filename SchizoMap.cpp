//
// Created by Jacob Friedman on 6/6/22.
//

#include "SchizoMap.h"


void SchizoMap::add(Object* obj, std::map<std::string, any_mapkv_t> attrs) {
    std::unordered_set<std::string> attr_names;
    for (auto const& attr : attrs) {
        attr_names.insert(attr.first);
    }
    obj_attrs.insert(std::pair<Object*, std::unordered_set<std::string>>(obj, attr_names));

    for (auto const& attr : attrs) {
        if (attr_metamap.contains(attr.first)) {
            auto &attr_map = attr_metamap[attr.first];
            auto &objs_with_attr = attr_map[attr.second];
            objs_with_attr.insert(obj);
        }
        else {
            std::map<any_mapkv_t, std::unordered_set<Object*>> new_attr_map;
            std::unordered_set<Object*> objs_with_attr;
            objs_with_attr.insert(obj);
            new_attr_map.insert(std::pair<any_mapkv_t, std::unordered_set<Object*>>(attr.second, objs_with_attr));
            attr_metamap.insert(std::pair<std::string, std::map<any_mapkv_t, std::unordered_set<Object*>>>(attr.first, new_attr_map));
        }
    }
}

std::unordered_set<Object*> SchizoMap::filter(std::string attr_name, any_mapkv_t attr_val){
    auto& attr_map = this->attr_metamap[attr_name];
    return attr_map[attr_val];
}