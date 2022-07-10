//
// Created by Jacob on 5/12/22.
//

#ifndef JANK_ENGINE_THEFIRSTMOVER_H
#define JANK_ENGINE_THEFIRSTMOVER_H

#ifdef _DARWIN
    #include <GLUT/glut.h>
#endif
#ifdef _WINDOWS
    #include <GL/glut.h>
#endif

#include <thread>
#include <chrono>
#include <iostream>
#include "Object.h"
#include "Graphics.h"

void start_motion();

void per_second_movement(int);

void end_motion();

static bool moving;

#endif //JANK_ENGINE_THEFIRSTMOVER_H
