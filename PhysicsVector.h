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

template<Unit units>
class PhysicsVector {
public:
    PhysicsScalar<units> x;
    PhysicsScalar<units> y;

    constexpr PhysicsVector(GLdouble x, GLdouble y) : x(x), y(y) { }
    constexpr PhysicsVector(PhysicsScalar<units> x, PhysicsScalar<units> y) : x(x), y(y) { }

    static PhysicsVector construct_polar(GLdouble radius, GLdouble angle) {
        return PhysicsVector(radius * std::cos(angle), radius * std::sin(angle));
    }

    constexpr friend PhysicsVector operator+(PhysicsVector first, PhysicsVector second) {
        return PhysicsVector(first.x+second.x, first.y+second.y);
    }
    constexpr friend PhysicsVector operator-(PhysicsVector first, PhysicsVector second) {
        return PhysicsVector(first.x-second.x, first.y-second.y);
    }
    constexpr PhysicsVector operator-() {
        return PhysicsVector(-x, -y);
    }

    constexpr friend PhysicsVector operator*(PhysicsVector vec, GLdouble n) {
        return PhysicsVector(vec.x*n, vec.y*n);
    }
    constexpr friend PhysicsVector operator*(GLdouble n, PhysicsVector vec) {
        return vec*n;
    }

    constexpr friend PhysicsVector operator/(PhysicsVector vec, GLdouble n) {
        return PhysicsVector(vec.x/n, vec.y/n);
    }
    constexpr friend PhysicsVector operator/(GLdouble n, const PhysicsVector& vec) {
        return PhysicsVector<units.inverse()>(n/vec.x, n/vec.y);
    }

    constexpr PhysicsVector& operator+=(PhysicsVector other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    constexpr PhysicsVector& operator-=(PhysicsVector other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    constexpr friend bool operator==(PhysicsVector first, PhysicsVector second) {
        return first.x == second.x && first.y == second.y;
    }

    friend std::ostream& operator<<(std::ostream& ost, PhysicsVector vector) {
        ost << "(" << vector.x << ", " << vector.y << ")";
        return ost;
    }
};

template<Unit firstUnits, Unit secondUnits>
constexpr auto operator*(PhysicsVector<firstUnits> first, PhysicsVector<secondUnits> second) {
    return PhysicsVector<firstUnits*secondUnits>(first.x*second.x, first.y*second.y);
}
template<Unit vecUnits, Unit scalarUnits>
constexpr auto operator*(PhysicsVector<vecUnits> vec, PhysicsScalar<scalarUnits> scalar) {
    return PhysicsVector<vecUnits*scalarUnits>(vec.x*scalar, vec.y*scalar);
}
template<Unit scalarUnits, Unit vecUnits>
constexpr auto operator*(PhysicsScalar<scalarUnits> scalar, PhysicsVector<vecUnits> vec) {
    return vec*scalar;
}

template<Unit units>
std::size_t hash_value(PhysicsVector<units> vec) {
    std::size_t seed = 0;
    boost::hash_combine(seed, vec.x);
    boost::hash_combine(seed, vec.y);
    return seed;
}

#endif //JANK_ENGINE_PHYSICSVECTOR_H
