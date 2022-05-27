//
// Created by Jacob Friedman on 5/26/22.
//

#ifndef JANK_ENGINE_GRAPHICS_H
#define JANK_ENGINE_GRAPHICS_H

#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <cmath>
#include <thread>
#include <chrono>
#include "Object.h"

void start_graphics(int *argcp, char *argv[]);
void load_regular_polygon(GLdouble num_sides, GLdouble side_len, GLdouble x, GLdouble y);
void display_func();
void display_objects();
#endif //JANK_ENGINE_GRAPHICS_H