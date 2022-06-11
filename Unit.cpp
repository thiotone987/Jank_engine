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
    std::vector<std::string> numerator;
    std::vector<int> numerator_exps;
    std::vector<std::string> denominator;
    std::vector<int> denominator_exps;

#define ADD_TO_NUM_OR_DENOM(_unit_name, _unit_exp) \
    if ((_unit_exp) > 0) { \
        numerator.emplace_back(_unit_name); \
        numerator_exps.push_back(_unit_exp); \
    } \
    else if ((_unit_exp) < 0) { \
        denominator.emplace_back(_unit_name); \
        denominator_exps.push_back(_unit_exp); \
    }

    ADD_TO_NUM_OR_DENOM("kg", unit.get_kg_exp())
    ADD_TO_NUM_OR_DENOM("m", unit.get_meters_exp())
    ADD_TO_NUM_OR_DENOM("s", unit.get_seconds_exp())
#undef ADD_TO_NUM_OR_DENOM

    for (int i = 0; i < numerator.size(); i++) {
        if (i != 0) ost << "*";
        ost << numerator[i];
        if (numerator_exps[i] > 1) ost << "^" << numerator_exps[i];
    }
    if (!denominator.empty()) ost << "/";

    if (denominator.size() > 1) ost << "(";
    for (int i = 0; i < denominator.size(); i++) {
        if (i != 0) ost << "*";
        ost << denominator[i];
        if (denominator_exps[i] > 1) ost << "^" << denominator_exps[i];
    }
    if (denominator.size() > 1) ost << ")";

    return ost;
}
