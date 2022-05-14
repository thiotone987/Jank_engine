//
// Created by Jacob on 5/12/22.
//

#ifndef JANK_ENGINE_PHYSICSVECTOR_H
#define JANK_ENGINE_PHYSICSVECTOR_H

#include <iostream>

class PhysicsVector {
private:
    double x;
    double y;

public:
    PhysicsVector();
    PhysicsVector(double, double);

    [[nodiscard]] double get_x() const;
    void set_x(double x);

    [[nodiscard]] double get_y() const;
    void set_y(double y);
    [[nodiscard]] PhysicsVector operator+(PhysicsVector&) const;
    [[nodiscard]] PhysicsVector operator+(PhysicsVector&&) const;

    PhysicsVector& operator+=(PhysicsVector&);
    PhysicsVector& operator+=(PhysicsVector&&);

    friend std::ostream& operator<<(std::ostream&, const PhysicsVector&);
};


#endif //JANK_ENGINE_PHYSICSVECTOR_H
