//
// Created by Jacob on 5/12/22.
//

#include "PhysicsVector.h"

PhysicsVector::PhysicsVector(double x, double y, Unit units) : units(units) {
    coords = std::shared_ptr<GLdouble[]>(new GLdouble[2]);
    coords[0] = x;
    coords[1] = y;
}

PhysicsVector PhysicsVector::construct_polar(double radius, double angle, Unit units) {
    return PhysicsVector(radius*std::cos(angle), radius*std::sin(angle), units);
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

Unit PhysicsVector::get_units() const {
    return units;
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

bool operator==(const PhysicsVector& vec1, const PhysicsVector& vec2) {
    return vec1.get_x() == vec2.get_x()
    && vec1.get_y() == vec2.get_y()
    && vec1.get_units() == vec2.get_units();
}

std::ostream& operator<<(std::ostream& ost, const PhysicsVector& vector) {
    ost << "("
        << vector.get_x() << " " <<  vector.get_units()
        << ", "
        << vector.get_y() << " " <<  vector.get_units()
        << ")";
    return ost;
}

PhysicsVector operator*(const PhysicsVector& vector, const Unit& units) {
    return PhysicsVector(vector.get_x(), vector.get_y(), vector.get_units()*units);
}

PhysicsVector operator*(const Unit& units, const PhysicsVector& vector) {
    return vector*units;
}


std::size_t hash_value(PhysicsVector const& vec) {
    std::size_t seed = 0;
    boost::hash_combine(seed, vec.get_x());
    boost::hash_combine(seed, vec.get_y());
    boost::hash_combine(seed, vec.get_units());
    return seed;
}
