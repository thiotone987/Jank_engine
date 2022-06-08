//
// Created by Jacob Friedman on 6/6/22.
//

#ifndef JANK_ENGINE_SCHIZOMAP_H
#define JANK_ENGINE_SCHIZOMAP_H

#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <concepts>
#include <boost/variant.hpp>
#include <boost/functional/hash.hpp>
#include "Object.h"
#include "PhysicsVector.h"

template<typename... attr_types>
class SchizoMapTemplate {
private:
    std::unordered_map<
        std::string,
        std::unordered_map<
            boost::variant<attr_types...>,
            std::unordered_set<Object*>,
            boost::hash<
                boost::variant<attr_types...>
            >
        >
    > attr_metamap;
    std::unordered_map<Object*, std::unordered_set<std::string>> objs_to_attr_names;
public:
    void add(Object* obj) {
        const auto& obj_attr_map = obj->get_attr_map<attr_types...>();

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
                std::unordered_map<boost::variant<attr_types...>, std::unordered_set<Object*>, boost::hash<boost::variant<attr_types...>>> new_attr_map;
                std::unordered_set<Object*> objs_with_attr;
                objs_with_attr.insert(obj);
                new_attr_map.insert(std::make_pair(attr_val, objs_with_attr));
                attr_metamap.insert(std::make_pair(attr_name, new_attr_map));
            }
        }
    }

    void remove(Object* obj) {
        // remove from attr_metamap
        auto obj_attr_map = obj->get_attr_map<attr_types...>();
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

    std::unordered_set<Object*> filter(const std::string& attr_name, const boost::variant<attr_types...>& attr_val) {
        return attr_metamap[attr_name][attr_val];
    }

    friend std::ostream& operator<<(std::ostream& ost, SchizoMapTemplate<attr_types...> schizo_map) {
        ost << "Objects: " << std::endl;
        for (const std::pair<Object*, std::unordered_set<std::string>>& temp : schizo_map.objs_to_attr_names) {
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
};


// Add types to the comma-separated list to get SchizoMap support for attributes of that type
typedef SchizoMapTemplate<PhysicsVector, int, std::string> SchizoMap;

#endif //JANK_ENGINE_SCHIZOMAP_H
