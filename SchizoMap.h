#ifndef JANK_ENGINE_SCHIZOMAP_H
#define JANK_ENGINE_SCHIZOMAP_H

#include <initializer_list>
#include <unordered_map>
#include <vector>
#include <ranges>
#include <unordered_set>
#include <concepts>
#include <boost/variant.hpp>
#include <boost/functional/hash.hpp>
#include <boost/iterator/transform_iterator.hpp>

#include "Object.h"
#include "PhysicsVector.h"

class SchizoMap {
private:
    std::unordered_map<
        std::string,
        std::unordered_map<
            Object::attr_variant_t,
            std::unordered_set<Object*>,
            boost::hash<Object::attr_variant_t>
        >
    > attr_metamap;
    std::unordered_map<Object*, std::unordered_set<std::string>> objs_to_attr_names;
    std::unordered_set<Object*> objects;
public:
    SchizoMap() = default;
    SchizoMap(std::initializer_list<Object*>);
    void add(Object *obj);
    void remove(Object *obj);
    auto begin() {
        return this->objects.begin();
    }

    auto end(){
        return this->objects.end();
    }

    std::unordered_set<Object*> filter(const std::string& attr_name, const Object::attr_variant_t& attr_val);

    friend std::ostream& operator<<(std::ostream& ost, const SchizoMap& schizo_map);
};

#endif //JANK_ENGINE_SCHIZOMAP_H
