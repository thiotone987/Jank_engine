//
// Created by Jacob Friedman on 5/31/22.
//

#ifndef JANK_ENGINE_UNIT_H
#define JANK_ENGINE_UNIT_H

#include <iostream>
#include <array>
#include <vector>

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
    constexpr friend bool operator==(Unit unit1, Unit unit2) {
        return unit1.meters_exp == unit2.meters_exp &&
               unit1.kg_exp == unit2.kg_exp &&
               unit1.seconds_exp == unit2.seconds_exp;
    };
//    friend std::ostream& operator<<(std::ostream& os, const Unit& unit);
};

const Unit METERS(1, 0, 0);
const Unit SECONDS(0, 1, 0);
const Unit KG(0, 0, 1);
const Unit UNITLESS(0, 0, 0);

#endif //JANK_ENGINE_UNIT_H