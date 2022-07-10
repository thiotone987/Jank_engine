#include <iostream>
#include "Object.h"
#include "Game.h"
#include "Graphics.h"
#include "Unit.h"
#include "SchizoMap.h"

int main(int argc, char* argv []) {
    PhysicsVector some_position = PhysicsVector(0.1, 0.2, METERS);
    Object obj(some_position);
    PhysicsVector some_other_position = PhysicsVector(0.2, 0.3, METERS);
    PhysicsVector some_velocity = PhysicsVector(0.03, 0.02, METERS/SECONDS);
    Object obj2(some_position, some_velocity);

    std::vector<Object*> hi = {&obj};
    Game game1(hi);
    std::vector<Object*> hii = {&obj2};
    Game game2(hii);

    glutInit(&argc, argv);
    start_graphics(&argc, argv);

    return 0;
}

void do_nothing();
