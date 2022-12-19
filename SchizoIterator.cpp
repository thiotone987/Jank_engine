//
// Created by Jacob Friedman on 12/18/22.
//

#include "SchizoIterator.h"

SchizoIterator::SchizoIterator(std::unordered_map<Object*, std::unordered_set<std::string>>::const_iterator map_it)
: map_it(map_it) {}

bool SchizoIterator::operator==(const SchizoIterator& other) const {
    return map_it == other.map_it;
}

Object *SchizoIterator::operator*() {
    return map_it->first;
}

SchizoIterator& SchizoIterator::operator++() {
    map_it++;
    return *this;
}
