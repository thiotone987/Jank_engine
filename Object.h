//
// Created by caryj on 5/10/2022.
//

#ifndef JANK_ENGINE_OBJECT_H
#define JANK_ENGINE_OBJECT_H


#include <vector>
#include <boost/variant.hpp>
#include <unordered_map>
#include "PhysicsVector.h"

class Object {
public:
    // Add types to the comma-separated list to get SchizoMap support for attributes of that type
    typedef boost::variant<int, std::string, PhysicsVector> attr_val_t;
private:
    PhysicsVector position;
    PhysicsVector velocity;
    std::string sprite_loc;
public:
    Object();
    explicit Object(PhysicsVector initial_position);
    Object(PhysicsVector initial_position, PhysicsVector initial_velocity);
    ~Object();
    void move(const PhysicsVector& displacement);

    [[nodiscard]] PhysicsVector get_velocity() const;
    void set_velocity(PhysicsVector);

    [[nodiscard]] PhysicsVector get_position() const;
    void set_position(PhysicsVector);

    [[nodiscard]] std::unordered_map<std::string, attr_val_t> get_attr_map() const {
        std::unordered_map<std::string, attr_val_t> output;
        // can't use make_pair because we need implicit conversion from _attr's type to boost::variant
#define ADD_ATTR(_attr) output.insert(std::pair<std::string, attr_val_t>(#_attr, _attr))
        ADD_ATTR(position);
        ADD_ATTR(velocity);
#undef ADD_ATTR
        return output;
    }

    friend std::ostream& operator<<(std::ostream& os, const Object& vector);
};

extern std::unordered_set<Object*> objects;

#endif //JANK_ENGINE_OBJECT_H
