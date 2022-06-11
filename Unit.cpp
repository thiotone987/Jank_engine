//
// Created by Jacob Friedman on 5/31/22.
//

#include "Unit.h"

std::size_t hash_value(Unit const& unit) {
    std::size_t seed = 0;
    boost::hash_combine(seed, unit.get_kg_exp());
    boost::hash_combine(seed, unit.get_seconds_exp());
    boost::hash_combine(seed, unit.get_meters_exp());
    return seed;
}

std::ostream& operator<<(std::ostream& ost, const Unit& unit) {
    if (unit == UNITLESS) {
        ost << "(unitless)";
        return ost;
    }

    // Each entry in the map represents a component of the unit (e.g. kilograms).
    // The string is the shortened name, e.g. "kg", and the int is the exponent, e.g. -2 in kg^-2
    std::map<std::string, int> numerator;
    std::map<std::string, int> denominator;

#define ADD_TO_APPROPRIATE_FRACTION_PART(_unit_name, _unit_exp) \
if ((_unit_exp) > 0) { \
    numerator.emplace(_unit_name, _unit_exp); \
} \
else if ((_unit_exp) < 0) { \
    denominator.emplace(_unit_name, _unit_exp); \
}

#define PRINT_FRACTION_PART(_part) \
for (auto iter=(_part).begin(); iter != (_part).end(); iter++) { \
    const std::string& unit_name = iter->first; \
    int unit_exp = iter->second; \
    if (iter != _part.begin()) ost << "*"; \
    ost << unit_name; \
    if (std::abs(unit_exp) > 1) ost << "^" << std::abs(unit_exp); \
}

    ADD_TO_APPROPRIATE_FRACTION_PART("kg", unit.get_kg_exp())
    ADD_TO_APPROPRIATE_FRACTION_PART("m", unit.get_meters_exp())
    ADD_TO_APPROPRIATE_FRACTION_PART("s", unit.get_seconds_exp())

    PRINT_FRACTION_PART(numerator)
    if (!denominator.empty()) ost << "/";
    if (denominator.size() > 1) ost << "(";
    PRINT_FRACTION_PART(denominator)
    if (denominator.size() > 1) ost << ")";

    return ost;

#undef ADD_TO_APPROPRIATE_FRACTION_PART
#undef PRINT_FRACTION_PART
}
