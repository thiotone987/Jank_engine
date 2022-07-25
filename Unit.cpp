#include "Unit.h"

std::size_t hash_value(Unit const& unit) {
    std::size_t seed = 0;
    boost::hash_combine(seed, unit.kg_exp);
    boost::hash_combine(seed, unit.seconds_exp);
    boost::hash_combine(seed, unit.meters_exp);
    return seed;
}

std::ostream& operator<<(std::ostream& ost, const Unit& unit) {
    // The better way to do this is to generate the string at compile-time, and just print it at runtime.
    // Sadly, std::map isn't constexpr (for any library), std::vector isn't constexpr (for libc++),
    //  and std::string isn't constexpr (for apple's libc++), making generating the string nearly impossible.
    // Once apple's libc++ makes std::vector and std::string constexpr, we should do this.
    
    if (unit == UNITLESS) {
        ost << "(unitless)";
        return ost;
    }

    // Each entry in the map represents a component of the unit (e.g. kilograms).
    // The string is the shortened name, e.g. "kg", and the int is the exponent, e.g. -2 in kg^-2
    std::map<std::string, int> numerator, denominator;

    #define ADD_TO_APPROPRIATE_FRACTION_PART(_unit_name, _unit_exp) \
    if ((_unit_exp) > 0) { \
        numerator.emplace(_unit_name, _unit_exp); \
    } \
    else if ((_unit_exp) < 0) { \
        denominator.emplace(_unit_name, - _unit_exp); \
    }

    #define PRINT_FRACTION_PART(_part) \
    for (auto iter=(_part).cbegin(); iter != (_part).cend(); iter++) { \
        const auto& [unit_abbrv, exp] = *iter; \
        if (iter != (_part).cbegin()) ost << "*"; \
        ost << unit_abbrv; \
        if (exp > 1) ost << "^" << exp; \
    }

    ADD_TO_APPROPRIATE_FRACTION_PART("kg", unit.kg_exp)
    ADD_TO_APPROPRIATE_FRACTION_PART("m", unit.meters_exp)
    ADD_TO_APPROPRIATE_FRACTION_PART("s", unit.seconds_exp)

    PRINT_FRACTION_PART(numerator)
    if (!denominator.empty()) {
        if (numerator.empty()) ost << "1";
        ost << "/";
    }
    if (denominator.size() > 1) ost << "(";
    PRINT_FRACTION_PART(denominator)
    if (denominator.size() > 1) ost << ")";

    return ost;

#undef ADD_TO_APPROPRIATE_FRACTION_PART
#undef PRINT_FRACTION_PART
}
