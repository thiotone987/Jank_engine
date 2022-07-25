#ifndef JANK_ENGINE_GAME_H
#define JANK_ENGINE_GAME_H

#include "glut.h"
#include <cmath>
#include <functional>
#include <vector>
#include <ranges>

#include "SchizoMap.h"
#include "Object.h"

void load_regular_polygon(GLdouble num_sides, GLdouble side_len, PhysicsVector<METERS> center_coords);

class Game {
private:
    SchizoMap objects;
    bool moving;
public:
    GLint windowID;

    explicit Game(SchizoMap& objects) noexcept;
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
