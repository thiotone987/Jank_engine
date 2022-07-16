//
// Created by caryj on 5/10/2022.
//

#include "Object.h"

std::unordered_set<Object*> objects;

Object::Object()
: Object(PhysicsVector<METERS>(0, 0), PhysicsVector<METERS/SECONDS>(0, 0)) {
}

Object::Object(PhysicsVector<METERS> initial_position)
: Object(initial_position, PhysicsVector<METERS/SECONDS>(0, 0)) {
}

Object::Object(PhysicsVector<METERS> initial_position, PhysicsVector<METERS/SECONDS> initial_velocity)
: position(initial_position), velocity(initial_velocity) {
}

std::ostream& operator<<(std::ostream& os, const Object& vector) {
    os << "object with position: " << vector.position << ", velocity: " << vector.velocity;
    return os;
}
