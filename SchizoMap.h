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

template<typename T>
concept Iterable = requires(T obj){
    obj.begin();
    obj.end();
};

class SchizoMap {
private:
    std::unordered_map<
        std::string,
        std::unordered_map<
            Object::attr_val_t,
            std::unordered_set<Object*>,
            boost::hash<Object::attr_val_t>
        >
    > attr_metamap;
    std::unordered_map<Object*, std::unordered_set<std::string>> objs_to_attr_names;
public:
    void add(Object *obj);
    void remove(Object *obj);
    std::unordered_set<Object*> filter(const std::string& attr_name, const Object::attr_val_t& attr_val);

    friend std::ostream& operator<<(std::ostream& ost, const SchizoMap& schizo_map);
};

#endif //JANK_ENGINE_SCHIZOMAP_H
