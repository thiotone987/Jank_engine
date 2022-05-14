//
// Created by Jacob on 5/12/22.
//

#ifndef JANK_ENGINE_THEFIRSTMOVER_H
#define JANK_ENGINE_THEFIRSTMOVER_H


#include <thread>
#include <chrono>
#include <iostream>
#include "Object.h"

void start_motion();

void end_motion();

static std::thread motion_thread;

static bool moving;

#endif //JANK_ENGINE_THEFIRSTMOVER_H
