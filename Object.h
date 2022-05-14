//
// Created by caryj on 5/10/2022.
//

#ifndef JANK_ENGINE_OBJECT_H
#define JANK_ENGINE_OBJECT_H


#include <vector>
#include "PhysicsVector.h"

class Object {
private:
    PhysicsVector position;
    PhysicsVector velocity;
public:
    Object();
    explicit Object(PhysicsVector initial_position);
    Object(PhysicsVector initial_position, PhysicsVector initial_velocity);
    ~Object();
    void move(PhysicsVector displacement);

    [[nodiscard]] PhysicsVector get_velocity() const;
    void set_velocity(PhysicsVector);

    [[nodiscard]] PhysicsVector get_position() const;
    void set_position(PhysicsVector);

    friend std::ostream& operator<<(std::ostream& os, const Object& vector);
};

extern std::vector<Object*> objects;

#endif //JANK_ENGINE_OBJECT_H
