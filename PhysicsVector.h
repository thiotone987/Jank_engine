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
#include "PhysicsScalar.h"

template<Unit U>
class PhysicsVector {
public:
    static constexpr Unit units = U;
    PhysicsScalar<units> x;
    PhysicsScalar<units> y;

    PhysicsVector(GLdouble x, GLdouble y) : x(x), y(y) { }
    PhysicsVector(PhysicsScalar<units> x, PhysicsScalar<units> y) : x(x), y(y) { }

    static PhysicsVector construct_polar(GLdouble radius, GLdouble angle) {
        return PhysicsVector(radius * std::cos(angle), radius * std::sin(angle));
    }

    friend PhysicsVector operator+(const PhysicsVector& first, const PhysicsVector& second) {
        return PhysicsVector(first.x+second.x, first.y+second.y);
    }

    friend PhysicsVector operator*(const PhysicsVector& vec, GLdouble n) {
        return PhysicsVector(vec.x*n, vec.y*n);
    }
    friend PhysicsVector operator*(GLdouble n, const PhysicsVector& vec) {
        return vec*n;
    }

    friend PhysicsVector operator/(const PhysicsVector& vec, GLdouble n) {
        return PhysicsVector(vec.x/n, vec.y/n);
    }
    friend PhysicsVector operator/(GLdouble n, const PhysicsVector& vec) {
        return vec/n;
    }

    PhysicsVector& operator+=(const PhysicsVector& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    PhysicsVector& operator-=(const PhysicsVector& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    friend bool operator==(const PhysicsVector& first, const PhysicsVector& second) {
        return first.x == second.x && first.y == second.y;
    }

    friend std::ostream& operator<<(std::ostream& ost, const PhysicsVector& vector) {
        ost << "(" << vector.x << ", " << vector.y << ")";
        return ost;
    }
};

template<Unit firstUnits, Unit secondUnits>
auto operator*(const PhysicsVector<firstUnits>& first, const PhysicsVector<secondUnits>& second) {
    return PhysicsVector<firstUnits*secondUnits>(first.x*second.x, first.y*second.y);
}
template<Unit vecUnits, Unit scalarUnits>
auto operator*(const PhysicsVector<vecUnits>& vec, PhysicsScalar<scalarUnits> scalar) {
    return PhysicsVector<vecUnits*scalarUnits>(vec.x*scalar, vec.y*scalar);
}
template<Unit scalarUnits, Unit vecUnits>
auto operator*(PhysicsScalar<scalarUnits> scalar, const PhysicsVector<vecUnits>& vec) {
    return vec*scalar;
}

template<Unit U>
std::size_t hash_value(PhysicsVector<U> const& vec) {
    std::size_t seed = 0;
    boost::hash_combine(seed, vec.x);
    boost::hash_combine(seed, vec.y);
    return seed;
}

#endif //JANK_ENGINE_PHYSICSVECTOR_H
