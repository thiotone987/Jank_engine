//
// Created by caryj on 5/10/2022.
//

#include "Object.h"

std::unordered_set<Object*> objects;

Object::Object()
: Object(PhysicsVector(0, 0, METERS), PhysicsVector(0, 0, METERS/SECONDS)) {
}

Object::Object(PhysicsVector initial_position)
: Object(std::move(initial_position), PhysicsVector(0, 0, METERS/SECONDS)) {
}

Object::Object(PhysicsVector initial_position, PhysicsVector initial_velocity)
: position(std::move(initial_position)), velocity(std::move(initial_velocity)) {
    objects.insert(this);
}

Object::~Object() {
    objects.erase(this);
}

void Object::move(const PhysicsVector& displacement) {
    this->position += displacement;
}

std::ostream& operator<<(std::ostream& os, const Object& vector) {
    os << "object with position: " << vector.position << ", velocity: " << vector.velocity;
    return os;
}
