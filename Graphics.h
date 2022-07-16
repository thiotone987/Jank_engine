//
// Created by Jacob Friedman on 5/26/22.
//

#ifndef JANK_ENGINE_GRAPHICS_H
#define JANK_ENGINE_GRAPHICS_H


#include "glut.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_opengl.h>
#include <cmath>
#include <thread>
#include <chrono>
#include <map>
#include <vector>
#include <string>
#include "Object.h"
#include "Game.h"

extern std::vector<Game*> games;

void start_graphics(int *argc_p, char *argv[]);
void start_two_windows(int *argc_p, char *argv[]);
int start_special_graphics(int *argc, char *argv[]);
int two_SDL_windows(int *argc, char *argv[]);
void load_regular_polygon(GLdouble num_sides, GLdouble side_len, const PhysicsVector<METERS>& center_coords);
void redisplay(int millis);
void display_func();
void display_func_1();
void display_func_2();
void load_objects();
void load_sprite(const std::string& file_path);
//the only difference between the two is the
//status in render queue
void load_background(const std::string& file_path);
#endif //JANK_ENGINE_GRAPHICS_H
