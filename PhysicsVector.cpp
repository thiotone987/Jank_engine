//
// Created by Jacob on 5/12/22.
//

#include "PhysicsVector.h"

PhysicsVector::PhysicsVector(Unit units, GLdouble x, GLdouble y) : x(x), y(y), units(units) {
}

PhysicsVector PhysicsVector::construct_polar(Unit units, double radius, double angle) {
    return PhysicsVector(units, radius * std::cos(angle), radius * std::sin(angle));
}


PhysicsVector PhysicsVector::operator+(const PhysicsVector& other) const {
//    if (this->units != other.units) {
//        throw std::invalid_argument("Cannot add two vectors with different units");
//    }
    return PhysicsVector(units, x + other.x, y + other.y);
}

PhysicsVector& PhysicsVector::operator+=(const PhysicsVector& other) {
//    if (this->units != other.units) {
//        throw std::invalid_argument("Cannot add two vectors with different units");
//    }
    x += other.x;
    y += other.y;
    return *this;
}

bool operator==(const PhysicsVector& vec1, const PhysicsVector& vec2) {
    return vec1.x == vec2.x
    && vec1.y == vec2.y
    && vec1.units == vec2.units;
}

std::ostream& operator<<(std::ostream& ost, const PhysicsVector& vector) {
    ost << "("
        << vector.x << " " <<  vector.units
        << ", "
        << vector.y << " " <<  vector.units
        << ")";
    return ost;
}

PhysicsVector operator*(const PhysicsVector& vector, const Unit& units) {
    return PhysicsVector(vector.units * units, vector.x, vector.y);
}

PhysicsVector operator*(const Unit& units, const PhysicsVector& vector) {
    return vector*units;
}

PhysicsVector operator*(const PhysicsVector& vec, const int n) {
    return PhysicsVector(vec.units, vec.x * n, vec.y * n);
}

PhysicsVector operator*(const int n, const PhysicsVector& vec) {
    return vec*n;
}

PhysicsVector operator/(const PhysicsVector& vec, const int n) {
    return PhysicsVector(vec.units, vec.x / n, vec.y / n);
}

PhysicsVector operator/(const int n, const PhysicsVector& vec) {
    return vec/n;
}

std::size_t hash_value(PhysicsVector const& vec) {
    std::size_t seed = 0;
    boost::hash_combine(seed, vec.x);
    boost::hash_combine(seed, vec.y);
    boost::hash_combine(seed, vec.units);
    return seed;
}
