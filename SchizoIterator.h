//
// Created by Jacob Friedman on 12/18/22.
//

#ifndef JANK_ENGINE_SCHIZOITERATOR_H
#define JANK_ENGINE_SCHIZOITERATOR_H

#include <unordered_map>
#include <string>
#include "Object.h"


class SchizoIterator {
    std::unordered_map<Object*, std::unordered_set<std::string>>::const_iterator map_it;
public:
    Object *operator*();
    SchizoIterator& operator++();
    explicit SchizoIterator(std::unordered_map<Object*, std::unordered_set<std::string>>::const_iterator map);
    bool operator==(const SchizoIterator& other) const;

};


#endif //JANK_ENGINE_SCHIZOITERATOR_H
