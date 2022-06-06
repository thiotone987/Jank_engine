//
// Created by Jacob on 5/12/22.
//

#include "PhysicsVector.h"

PhysicsVector::PhysicsVector() : PhysicsVector(0, 0) {
}

PhysicsVector::PhysicsVector(double x, double y) : PhysicsVector(x, y, UNITLESS) {
}

PhysicsVector::PhysicsVector(double x, double y, Unit units) : units(units) {
    coords = std::shared_ptr<GLdouble>(new GLdouble[2]);
    coords[0] = x;
    coords[1] = y;
}

PhysicsVector PhysicsVector::construct_polar(double radius, double angle) {
    return PhysicsVector(radius*std::cos(angle), radius*std::sin(angle));
}


double PhysicsVector::get_x() const {
    return coords[0];
}

void PhysicsVector::set_x(double x) {
    coords[0] = x;
}

double PhysicsVector::get_y() const {
    return coords[1];
}

void PhysicsVector::set_y(double y) {
    coords[1] = y;
}

GLdouble* PhysicsVector::as_glvector() const {
    return this->coords.get();
}


PhysicsVector PhysicsVector::operator+(const PhysicsVector& other) const {
    if (this->units != other.units) {
        throw std::invalid_argument("Cannot add two vectors with different units");
    }
    return PhysicsVector(this->get_x() + other.get_x(), this->get_y() + other.get_y(), units);
}

PhysicsVector& PhysicsVector::operator+=(const PhysicsVector& other) {
    if (this->units != other.units) {
        throw std::invalid_argument("Cannot add two vectors with different units");
    }
    this->set_x(this->get_x()+other.get_x());
    this->set_y(this->get_y()+other.get_y());
    return *this;
}

std::ostream& operator<<(std::ostream& os, const PhysicsVector& vector) {
    os << "(" << vector.get_x() << ", " << vector.get_y() << ")";
    return os;
}
