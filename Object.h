#ifndef JANK_ENGINE_OBJECT_H
#define JANK_ENGINE_OBJECT_H


#include <vector>
#include <boost/variant.hpp>
#include <unordered_map>
#include "PhysicsVector.h"

class Object {
public:
    // Add types to the comma-separated list to get SchizoMap support for attributes of that type
    using attr_variant_t = boost::variant<int, std::string, PhysicsVector<METERS>, PhysicsVector<METERS/SECONDS>>;

    PhysicsVector<METERS> position;
    PhysicsVector<METERS/SECONDS> velocity;

    Object();
    explicit Object(PhysicsVector<METERS> initial_position);
    Object(PhysicsVector<METERS> initial_position, PhysicsVector<METERS/SECONDS> initial_velocity);

    [[nodiscard]] std::unordered_map<std::string, attr_variant_t> get_attr_map() const;

    friend std::ostream& operator<<(std::ostream& os, const Object& vector);
};


#endif //JANK_ENGINE_OBJECT_H
