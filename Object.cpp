//
// Created by caryj on 5/10/2022.
//

#include "Object.h"

std::unordered_set<Object*> objects;

Object::Object()
: Object(PhysicsVector(METERS, 0, 0), PhysicsVector(METERS / SECONDS, 0, 0)) {
}

Object::Object(PhysicsVector initial_position)
: Object(std::move(initial_position), PhysicsVector(METERS / SECONDS, 0, 0)) {
}

Object::Object(PhysicsVector initial_position, PhysicsVector initial_velocity)
: position(std::move(initial_position)), velocity(std::move(initial_velocity)) {
}

std::ostream& operator<<(std::ostream& os, const Object& vector) {
    os << "object with position: " << vector.position << ", velocity: " << vector.velocity;
    return os;
}
