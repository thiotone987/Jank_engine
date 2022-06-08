//
// Created by Jacob Friedman on 5/31/22.
//

#include "Unit.h"

std::size_t hash_value(Unit const& unit) {
    std::size_t seed = 0;
    boost::hash_combine(seed, unit.get_kg_exp());
    boost::hash_combine(seed, unit.get_seconds_exp());
    boost::hash_combine(seed, unit.get_meters_exp());
}

//std::ostream& operator<<(std::ostream& os, const Unit& unit) {
//
//}