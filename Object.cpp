//
// Created by caryj on 5/10/2022.
//

#include "Object.h"

std::vector<Object*> objects;

Object::Object() : Object(PhysicsVector(0, 0, METERS), PhysicsVector(0, 0, METERS/SECONDS)) {
}

Object::Object(PhysicsVector initial_position) : Object(initial_position, PhysicsVector(0, 0, METERS/SECONDS)) {
}

Object::Object(PhysicsVector initial_position, PhysicsVector initial_velocity) {
    objects.push_back(this);
    this->position = initial_position;
    this->velocity = initial_velocity;
}

Object::~Object() {
    auto object_iter = std::find(objects.begin(), objects.end(), this);
    if (object_iter != objects.end()) objects.erase(object_iter);
}

PhysicsVector Object::get_position() const {
    return this->position;
}

void Object::set_position(PhysicsVector position) {
    this->position = position;
}

PhysicsVector Object::get_velocity() const {
    return this->velocity;
}

void Object::set_velocity(PhysicsVector velocity) {
    this->velocity = velocity;
}

void Object::move(PhysicsVector displacement) {
    this->position += displacement;
}

std::ostream& operator<<(std::ostream& os, const Object& vector) {
    os << "position: " << vector.get_position() << ", velocity: " << vector.get_velocity();
    return os;
}