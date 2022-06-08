//
// Created by Jacob Friedman on 6/6/22.
//

#ifndef JANK_ENGINE_SCHIZOMAP_H
#define JANK_ENGINE_SCHIZOMAP_H

#include <map>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <boost/type_erasure/any.hpp>
#include <boost/type_erasure/operators.hpp>
#include "Object.h"

typedef
boost::type_erasure::any<
    boost::mpl::vector<
        boost::type_erasure::copy_constructible<>,
        boost::type_erasure::destructible<>,
        boost::type_erasure::less_than_comparable<>
    >
>
any_mapkv_t;

class SchizoMap {
private:
    std::map<std::string, std::map<any_mapkv_t, std::unordered_set<Object*>>> attr_metamap;
    std::map<Object*, std::unordered_set<std::string>> obj_attrs;
public:
    void add(Object* obj, std::map<std::string, any_mapkv_t> attrs);
    void remove(Object* obj);
    std::unordered_set<Object*> filter(std::string attr_name, any_mapkv_t attr_val);



};


#endif //JANK_ENGINE_SCHIZOMAP_H
