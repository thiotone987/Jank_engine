//
// Created by Jacob on 5/12/22.
//

#include "TheFirstMover.h"

void start_motion() {
    moving = true;
    motion_thread = std::thread([&](){
        while (moving) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            for (Object *obj: objects) {
                obj->move(obj->get_velocity());
            }
        }
    });
}

void end_motion() {
    moving = false;
    motion_thread.join();
}