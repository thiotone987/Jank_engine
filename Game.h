//
// Created by Jacob Friedman on 6/6/22.
//

#ifndef JANK_ENGINE_GAME_H
#define JANK_ENGINE_GAME_H

#include <cmath>
#include <functional>
#include <vector>
#include "Object.h"

class Game {
private:
    std::vector<Object> objects;
public:
    void load();
    void run();
    void stop_run();
    void unload();
};


#endif //JANK_ENGINE_GAME_H
