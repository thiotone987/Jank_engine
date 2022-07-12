//
// Created by Jacob on 5/12/22.
//

#ifndef JANK_ENGINE_PHYSICSVECTOR_H
#define JANK_ENGINE_PHYSICSVECTOR_H


#ifdef _DARWIN
    #include <OpenGL/gl.h>
#endif
#ifdef _WINDOWS
    #include <GL/gl.h>
#endif

#include <iostream>
#include <cmath>
#include <memory>
#include <unordered_set>
#include <boost/functional/hash.hpp>
#include "Unit.h"

class PhysicsVector {
public:
    const Unit units;
    GLdouble x;
    GLdouble y;

    PhysicsVector(Unit units, GLdouble x, GLdouble y);
    static PhysicsVector construct_polar(Unit units, GLdouble radius, GLdouble angle);

    [[nodiscard]] PhysicsVector operator+(const PhysicsVector&) const;
    friend PhysicsVector operator*(const PhysicsVector&, const Unit&);
    friend PhysicsVector operator*(const Unit&, const PhysicsVector&);
    friend PhysicsVector operator*(const PhysicsVector&, int);
    friend PhysicsVector operator*(int, const PhysicsVector&);
    friend PhysicsVector operator/(const PhysicsVector&, int);
    friend PhysicsVector operator/(int, const PhysicsVector&);

    PhysicsVector& operator+=(const PhysicsVector&);

    friend bool operator==(const PhysicsVector& vec1, const PhysicsVector& vec2);

    friend std::ostream& operator<<(std::ostream&, const PhysicsVector&);
};

std::size_t hash_value(PhysicsVector const& vec);


#endif //JANK_ENGINE_PHYSICSVECTOR_H
