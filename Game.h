//
// Created by Jacob Friedman on 6/6/22.
//

#ifndef JANK_ENGINE_GAME_H
#define JANK_ENGINE_GAME_H

#ifdef _DARWIN
    #include <GLUT/glut.h>
#endif
#ifdef _WINDOWS
    #include <GL/glut.h>
#endif

#include <cmath>
#include <functional>
#include <vector>
#include <ranges>

#include "Object.h"

void load_regular_polygon(GLdouble num_sides, GLdouble side_len, const PhysicsVector& center_coords);

class Game {
private:
    std::vector<Object*> objects;
    bool moving;
public:
    GLint windowID;

    explicit Game(std::vector<Object*>& objects) noexcept;
    void my_display_func();
    void load();
    void run();
    void stop_run();
    void unload();
    void start_motion();
    void per_second_movement(int help);
    void end_motion();
};

#endif //JANK_ENGINE_GAME_H
