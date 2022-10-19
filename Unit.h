#ifndef JANK_ENGINE_UNIT_H
#define JANK_ENGINE_UNIT_H

#include <iostream>
#include <array>
#include <vector>
#include <boost/functional/hash.hpp>

class Unit {
public:
    const int meters_exp;
    const int seconds_exp;
    const int kg_exp;
    constexpr Unit(int meters_exp, int seconds_exp, int kg_exp) noexcept
        : meters_exp(meters_exp), seconds_exp(seconds_exp), kg_exp(kg_exp)  {
    }

    constexpr friend Unit operator*(const Unit unit1, const Unit unit2) {
        return Unit(unit1.meters_exp + unit2.meters_exp,
                    unit1.seconds_exp + unit2.seconds_exp,
                    unit1.kg_exp + unit2.kg_exp);
    }
    constexpr friend Unit operator/(const Unit unit1, const Unit unit2) {
        return Unit(unit1.meters_exp - unit2.meters_exp,
                    unit1.seconds_exp - unit2.seconds_exp,
                    unit1.kg_exp - unit2.kg_exp);
    }
    constexpr friend Unit operator^(const Unit unit, const int exp) {
        return Unit(unit.meters_exp*exp,
                    unit.seconds_exp*exp,
                    unit.kg_exp*exp);
    }
    constexpr friend bool operator==(Unit unit1, Unit unit2) {
        return unit1.meters_exp == unit2.meters_exp &&
               unit1.seconds_exp == unit2.seconds_exp &&
               unit1.kg_exp == unit2.kg_exp;
    }

    constexpr Unit inverse() const {
        return Unit(-meters_exp, -seconds_exp, -kg_exp);
    }

    friend std::ostream& operator<<(std::ostream& ost, const Unit& unit);
};

std::size_t hash_value(Unit const& unit);

constexpr Unit METERS(1, 0, 0);
constexpr Unit SECONDS(0, 1, 0);
constexpr Unit KILOGRAMS(0, 0, 1);
constexpr Unit UNITLESS(0, 0, 0);

#endif //JANK_ENGINE_UNIT_H
