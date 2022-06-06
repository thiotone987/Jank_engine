//
// Created by Jacob Friedman on 6/5/22.
//

#ifndef JANK_ENGINE_INPUT_H
#define JANK_ENGINE_INPUT_H

#include <SDL.h>

class Input {
private:
    //stuff to implement here later
    SDL_Texture * texture;
    SDL_Renderer * renderer;
    SDL_Window * window;
    SDL_Event event;
    const Uint8* currentKeyStates;
public:
    static constexpr char NO_KEY = '\0';
    char getKey();
};


#endif //JANK_ENGINE_INPUT_H