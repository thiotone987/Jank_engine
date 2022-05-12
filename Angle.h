//
// Created by Jacob on 5/12/22.
//

#ifndef JANK_ENGINE_ANGLE_H
#define JANK_ENGINE_ANGLE_H

#include <numbers>
#include <cmath>

class Angle {

private:
    double radians;
public:
    static constexpr double ROTATION = 2*std::numbers::pi;

    explicit Angle(double);

    [[nodiscard]] double unbounded_radians() const;
    [[nodiscard]] double bounded_radians() const;

    [[nodiscard]] Angle operator+(Angle&) const;
    [[nodiscard]] Angle operator+(Angle&&) const;
    [[nodiscard]] Angle operator-(Angle&) const;
    [[nodiscard]] Angle operator-(Angle&&) const;

    Angle& operator+=(Angle&);
    Angle& operator+=(Angle&&);
    Angle& operator-=(Angle&);
    Angle& operator-=(Angle&&);

    bool same_direction(Angle&) const;
    bool same_direction(Angle&&) const;
};


#endif //JANK_ENGINE_ANGLE_H
