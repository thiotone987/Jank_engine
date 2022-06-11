//
// Created by Jacob Friedman on 5/31/22.
//

#ifndef JANK_ENGINE_UNIT_H
#define JANK_ENGINE_UNIT_H

#include <iostream>
#include <array>
#include <vector>
#include <boost/functional/hash.hpp>

class Unit {
private:
    int meters_exp;
    int seconds_exp;
    int kg_exp;
public:
    constexpr Unit(int meters_exp, int seconds_exp, int kg_exp) noexcept {
        this->meters_exp = meters_exp;
        this->seconds_exp = seconds_exp;
        this->kg_exp = kg_exp;
    };
    [[nodiscard]] constexpr int get_meters_exp() const { return meters_exp; };
    [[nodiscard]] constexpr int get_seconds_exp() const { return seconds_exp; };
    [[nodiscard]] constexpr int get_kg_exp() const { return kg_exp; };

    constexpr friend Unit operator*(Unit unit1, Unit unit2) {
        return Unit(unit1.get_meters_exp() + unit2.get_meters_exp(),
                    unit1.get_seconds_exp() + unit2.get_seconds_exp(),
                    unit1.get_kg_exp() + unit2.get_kg_exp());
    };
    constexpr friend Unit operator/(Unit unit1, Unit unit2) {
        return Unit(unit1.get_meters_exp() - unit2.get_meters_exp(),
                    unit1.get_seconds_exp() - unit2.get_seconds_exp(),
                    unit1.get_kg_exp() - unit2.get_kg_exp());
    };
    constexpr friend Unit operator^(Unit unit, int exp) {
        return Unit(unit.get_meters_exp()*exp,
                    unit.get_seconds_exp()*exp,
                    unit.get_kg_exp()*exp);
    }

    constexpr friend bool operator==(Unit unit1, Unit unit2) {
        return unit1.meters_exp == unit2.meters_exp &&
               unit1.kg_exp == unit2.kg_exp &&
               unit1.seconds_exp == unit2.seconds_exp;
    };
    friend std::ostream& operator<<(std::ostream& ost, const Unit& unit);
};

std::size_t hash_value(Unit const& unit);

constexpr Unit METERS(1, 0, 0);
constexpr Unit SECONDS(0, 1, 0);
constexpr Unit KILOGRAMS(0, 0, 1);
constexpr Unit UNITLESS(0, 0, 0);

#endif //JANK_ENGINE_UNIT_H
