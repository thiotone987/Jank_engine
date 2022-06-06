//
// Created by Jacob Friedman on 6/6/22.
//

#ifndef JANK_ENGINE_SCHIZOMAP_H
#define JANK_ENGINE_SCHIZOMAP_H

#include <map>
#include <vector>
#include <unordered_set>
#include "Object.h"

class SchizoMap {
private:
    std::map<std::string, std::map<int, std::unordered_set<Object*>>> attr_metamap;
    std::map<Object*, std::unordered_set<std::string>> obj_attrs;
public:
    void add(Object* obj, std::map<std::string, int> attrs);
    void remove(Object* obj);
    std::unordered_set<Object*> filter(std::string attr_name, int attr_val);



};


#endif //JANK_ENGINE_SCHIZOMAP_H
