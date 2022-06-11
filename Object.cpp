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

PhysicsVector Object::get_position() const {
    return this->position;
}

void Object::set_position(PhysicsVector position) {
    this->position = std::move(position);
}

PhysicsVector Object::get_velocity() const {
    return this->velocity;
}

void Object::set_velocity(PhysicsVector velocity) {
    this->velocity = std::move(velocity);
}

void Object::move(const PhysicsVector& displacement) {
    this->position += displacement;
}

std::ostream& operator<<(std::ostream& os, const Object& vector) {
    os << "position: " << vector.get_position() << ", velocity: " << vector.get_velocity();
    return os;
}
