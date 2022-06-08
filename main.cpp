#include <iostream>
#include <SDL.h>
#include "Object.h"
#include "TheFirstMover.h"
#include "Graphics.h"
#include "Unit.h"
#include "SchizoMap.h"
#include <boost/any.hpp>

int main(int argc, char* argv []) {
//    Object obj(PhysicsVector(-0.5, 0.5, Unit(0, 0, 0)), PhysicsVector(-0.01, 0.02, Unit(0, 0, 0)));
//    Object obj2(PhysicsVector(0, 0, Unit(0, 0, 0)), PhysicsVector(0.05, 0, Unit(0, 0, 0)));
//    start_motion();
//    start_graphics(&argc, argv);
    Unit velocity = METERS/SECONDS;
    PhysicsVector some_distance = PhysicsVector(1, 2, METERS);
    Object obj(some_distance);
    Object obj2(PhysicsVector(2, 3, METERS));
    SchizoMap help;
    std::map<std::string, any_mapkv_t> obj_attrs;
    obj_attrs.insert(std::pair<std::string, any_mapkv_t>("hi", "hooo"));
    std::map<std::string, any_mapkv_t> obj2_attrs;
    obj2_attrs.insert(std::pair<std::string, any_mapkv_t>("hi", "hooo"));
    help.add(&obj, obj_attrs);
    help.add(&obj2, obj2_attrs);
    auto a = help.filter("hi", "hooo");
    for (const auto& aa : a) {
        std::cout << aa->get_position() << std::endl;
    }
//
//    Object obj1(PhysicsVector(0.5, 0.2), PhysicsVector(0.05, 0.02));
//    start_motion();
//
//    start_graphics(&argc, argv);
//
//    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
//        return 1;
//    }

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