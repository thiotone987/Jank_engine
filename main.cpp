#include <iostream>
#include "Object.h"
#include "TheFirstMover.h"
#include "Graphics.h"
#include "Unit.h"
#include "SchizoMap.h"

int main(int argc, char* argv []) {
    PhysicsVector some_distance = PhysicsVector(0.1, 0.2, METERS);
    Object obj(some_distance);
    PhysicsVector some_velocity = PhysicsVector(0.03, 0.02, METERS/SECONDS);
    Object obj2(some_distance, some_velocity);
    SchizoMap schizo_map;
    schizo_map.add(&obj);
    schizo_map.add(&obj2);
    std::cout << schizo_map << std::endl;
    schizo_map.remove(&obj);
    auto filter_result = schizo_map.filter("position", PhysicsVector(1, 2, METERS));
    for (const auto& obj_p : filter_result) {
        std::cout << *obj_p << std::endl;
    }
    //glutInit(&argc, argv);

    //start_motion();
    start_special_graphics(&argc, argv);

    return 0;
}

void do_nothing();
