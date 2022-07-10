//
// Created by Jacob on 5/12/22.
//

#ifndef JANK_ENGINE_PHYSICSVECTOR_H
#define JANK_ENGINE_PHYSICSVECTOR_H

#include <iostream>
#include <GLUT/glut.h>
#include <cmath>
#include <memory>
#include <unordered_set>
#include <boost/functional/hash.hpp>
#include "Unit.h"

class PhysicsVector {
private:
    std::shared_ptr<GLdouble[]> coords;
    Unit units;
public:
    PhysicsVector(GLdouble x, GLdouble y, Unit units);

    static PhysicsVector construct_polar(GLdouble radius, GLdouble angle, Unit units);

    [[nodiscard]] GLdouble get_x() const;
    void set_x(GLdouble x);
    [[nodiscard]] GLdouble get_y() const;
    void set_y(GLdouble y);
    [[nodiscard]] Unit get_units() const;

    [[nodiscard]] const GLdouble* as_glvector() const;

    [[nodiscard]] PhysicsVector operator+(const PhysicsVector&) const;
    friend PhysicsVector operator*(const PhysicsVector&, const Unit&);
    friend PhysicsVector operator*(const Unit&, const PhysicsVector&);

    PhysicsVector& operator+=(const PhysicsVector&);

    friend bool operator==(const PhysicsVector& vec1, const PhysicsVector& vec2);

    friend std::ostream& operator<<(std::ostream&, const PhysicsVector&);
};

std::size_t hash_value(PhysicsVector const& vec);


#endif //JANK_ENGINE_PHYSICSVECTOR_H
