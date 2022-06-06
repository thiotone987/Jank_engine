#include <iostream>
#include <SDL.h>
#include "Object.h"
#include "TheFirstMover.h"
#include "Graphics.h"
#include "Unit.h"

int main(int argc, char* argv []) {
//    Object obj(PhysicsVector(-0.5, 0.5, Unit(0, 0, 0)), PhysicsVector(-0.01, 0.02, Unit(0, 0, 0)));
//    Object obj2(PhysicsVector(0, 0, Unit(0, 0, 0)), PhysicsVector(0.05, 0, Unit(0, 0, 0)));
//    start_motion();
//    start_graphics(&argc, argv);
    Unit velocity = METERS/SECONDS;
    PhysicsVector some_distance = PhysicsVector(1, 2, METERS);
    PhysicsVector some_velocity = PhysicsVector(2, 4, METERS);

    Object obj1(PhysicsVector(0.5, 0.2), PhysicsVector(0.05, 0.02));
    start_motion();

    start_graphics(&argc, argv);

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

//
//    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
//        return 1;
//    }
//
//    SDL_Quit();

    return 0;
}

void do_nothing();