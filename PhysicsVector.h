//
// Created by Jacob on 5/12/22.
//

#ifndef JANK_ENGINE_PHYSICSVECTOR_H
#define JANK_ENGINE_PHYSICSVECTOR_H


#include "glut.h"
#include <iostream>
#include <cmath>
#include <memory>
#include <unordered_set>
#include <boost/functional/hash.hpp>
#include "Unit.h"

template<Unit U>
class PhysicsVector {
public:
    static constexpr Unit units = U;
    GLdouble x;
    GLdouble y;

    PhysicsVector(GLdouble x, GLdouble y) : x(x), y(y) {
    }

    static PhysicsVector construct_polar(GLdouble radius, GLdouble angle) {
        return PhysicsVector(radius * std::cos(angle), radius * std::sin(angle));
    }

    friend PhysicsVector operator+(const PhysicsVector& first, const PhysicsVector& second) {
        return PhysicsVector<U>(first.x+second.x, first.y+second.y);
    }

    template<Unit U2>
    PhysicsVector<U*U2> times_unit() {
        return PhysicsVector<U*U2>(x, y);
    }

    friend PhysicsVector operator*(const PhysicsVector& vec, const Unit& unit) {
        return PhysicsVector<U*unit>(vec.x, vec.y);
    }
    friend PhysicsVector operator*(const Unit& unit, const PhysicsVector& vec) {
        return vec*unit;
    }
    friend PhysicsVector operator*(const PhysicsVector& vec, GLdouble n) {
        return PhysicsVector<U>(vec.x*n, vec.y*n);
    }
    friend PhysicsVector operator*(GLdouble n, const PhysicsVector& vec) {
        return vec*n;
    }
    friend PhysicsVector operator/(const PhysicsVector& vec, GLdouble n) {
        return PhysicsVector<U>(vec.x/n, vec.y/n);
    }
    friend PhysicsVector operator/(GLdouble n, const PhysicsVector& vec) {
        return vec/n;
    }

    PhysicsVector& operator+=(const PhysicsVector<U>& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    friend bool operator==(const PhysicsVector<U>& first, const PhysicsVector<U>& second) {
        return first.x == second.x && first.y == second.y;
    }

    friend std::ostream& operator<<(std::ostream& ost, const PhysicsVector<U>& vector) {
        ost << "("
            << vector.x << " " <<  PhysicsVector<U>::units
            << ", "
            << vector.y << " " <<  PhysicsVector<U>::units
            << ")";
        return ost;
    }
};

template<Unit U>
std::size_t hash_value(PhysicsVector<U> const& vec) {
    std::size_t seed = 0;
    boost::hash_combine(seed, vec.x);
    boost::hash_combine(seed, vec.y);
    return seed;
}

#endif //JANK_ENGINE_PHYSICSVECTOR_H
