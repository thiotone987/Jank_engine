#ifndef JANK_ENGINE_OBJECT_H
#define JANK_ENGINE_OBJECT_H


#include <vector>
#include <boost/variant.hpp>
#include <unordered_map>
#include "PhysicsVector.h"

class Object {
public:
    // Add types to the comma-separated list to get SchizoMap support for attributes of that type
    typedef boost::variant<int, std::string, PhysicsVector<METERS>, PhysicsVector<METERS/SECONDS>> attr_variant_t;

    PhysicsVector<METERS> position;
    PhysicsVector<METERS/SECONDS> velocity;

    Object();
    explicit Object(PhysicsVector<METERS> initial_position);
    Object(PhysicsVector<METERS> initial_position, PhysicsVector<METERS/SECONDS> initial_velocity);

    [[nodiscard]] std::unordered_map<std::string, attr_variant_t> get_attr_map() const {
        std::unordered_map<std::string, attr_variant_t> output;
        #define ADD_ATTR(_attr) output.insert(std::make_pair(#_attr, _attr))
        ADD_ATTR(position);
        ADD_ATTR(velocity);
        #undef ADD_ATTR
        return output;
    }

    friend std::ostream& operator<<(std::ostream& os, const Object& vector);
};

extern std::unordered_set<Object*> objects;


#endif //JANK_ENGINE_OBJECT_H
