//
// Created by Jacob on 5/12/22.
//

#include "PhysicsVector.h"

PhysicsVector::PhysicsVector() : PhysicsVector(0, 0) {
}

PhysicsVector::PhysicsVector(double x, double y) {
    this->x = x;
    this->y = y;
}

double PhysicsVector::get_x() const {
    return x;
}

void PhysicsVector::set_x(double x) {
    this->x = x;
}

double PhysicsVector::get_y() const {
    return y;
}

void PhysicsVector::set_y(double y) {
    this->y = y;
}

PhysicsVector PhysicsVector::operator+(const PhysicsVector& other) const {
    return {this->get_x()+other.get_x(), this->get_y()+other.get_y()};
}

PhysicsVector& PhysicsVector::operator+=(const PhysicsVector& other) {
    this->set_x(this->get_x()+other.get_x());
    this->set_y(this->get_y()+other.get_y());
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PhysicsVector& vector) {
    os << "(" << vector.get_x() << ", " << vector.get_y() << ")";
    return os;
}
