#include <iostream>
#include "Object.h"
#include "Game.h"
#include "Graphics.h"
#include "Unit.h"
#include "SchizoMap.h"

int main(int argc, char* argv []) {
    bool flag = false;
    PhysicsVector some_position = PhysicsVector<METERS>(0.1, 0.2);
    Object obj(some_position);
    PhysicsVector some_velocity = PhysicsVector<METERS/SECONDS>(0.03, 0.02);
    Object obj2(some_position, some_velocity);
    SchizoMap hi;
    for (double i = -0.5; i < 0.5; i += 0.01) {
        PhysicsVector pos = PhysicsVector<METERS>(i, i);
        PhysicsVector v = PhysicsVector<METERS/SECONDS>( i, i);
        hi.add(new Object(pos, v));
    }
    //glutInit(&argc, argv);
    //start_motion();
    start_special_graphics(&argc, argv);

    return 0;
}

void do_nothing();
