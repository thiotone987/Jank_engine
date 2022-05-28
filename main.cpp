#include <iostream>
#include <SDL.h>
#include "Object.h"
#include "TheFirstMover.h"
#include "Graphics.h"


int main(int argc, char* argv []) {
    Object obj(PhysicsVector(-0.5, 0.5), PhysicsVector(-0.01, 0.02));
    Object obj2(PhysicsVector(0, 0), PhysicsVector(0.05, 0));
    start_motion();
    start_graphics(&argc, argv);

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Quit();

    return 0;
}