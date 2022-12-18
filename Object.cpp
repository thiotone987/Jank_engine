#include "Object.h"
#include <fmt/format.h>

Object::Object()
: Object(PhysicsVector<METERS>(0, 0), PhysicsVector<METERS/SECONDS>(0, 0)) {
}

Object::Object(PhysicsVector<METERS> initial_position)
: Object(initial_position, PhysicsVector<METERS/SECONDS>(0, 0)) {
}

Object::Object(PhysicsVector<METERS> initial_position, PhysicsVector<METERS/SECONDS> initial_velocity)
: position(initial_position), velocity(initial_velocity) {
}

std::unordered_map<std::string, Object::attr_variant_t> Object::get_attr_map() const {
    return {{"position", position}, {"velocity", velocity}};
}

std::ostream& operator<<(std::ostream& os, const Object& vector) {
    os << "object with position: " << vector.position << ", velocity: " << vector.velocity;
    return os;
}
