//
// Created by Jacob Friedman on 5/26/22.
//

#include "Graphics.h"
#include "Game.h"

std::vector<Game*> games;

void start_graphics(int* argc_p, char* argv[]){
    for (Game *game : games) {
        game->load();
        game->run();
    }

    glutMainLoop();
}

void start_special_graphics(int width, int height){
    const char* title = "help";
    SDL_DisplayMode currentMode;
    SDL_Window *sdlWindow = SDL_CreateWindow(title,
                                             SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                             0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
    SDL_CreateWindowAndRenderer(0, 0,SDL_WINDOW_FULLSCREEN_DESKTOP,
                                &sdlWindow, &sdlRenderer);

    int dispIndex;
    int bpp = 0;

    int If_this_is_not_zero_we_have_issues = SDL_GetCurrentDisplayMode(dispIndex, &currentMode);
    const char* vidDriver = SDL_GetCurrentVideoDriver();

    if(If_this_is_not_zero_we_have_issues != 0){
        SDL_Log("Display mode dun work bruh (dispIndex: %d) (error: %s)", dispIndex, SDL_GetError());
    }
    else{
        SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", dispIndex, currentMode.w, currentMode.h, currentMode.refresh_rate);
    }

    if(vidDriver == nullptr){
        SDL_Log("No Video Driver? NO HAPPINESS (error: %s)", SDL_GetError());
    }
    else{
        SDL_Log("Current Video Driver: %s", vidDriver);
    }

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        fprintf(stderr, "Video initilization screwed us over: %s\n",
                SDL_GetError());
        //insert some intelligent way to kill the program
    }
    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
    SDL_RenderClear(sdlRenderer);
    SDL_RenderPresent(sdlRenderer);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    SDL_RenderSetLogicalSize(sdlRenderer, width, height);

    //The code below draws a texture to test the efficacy of the renderer

    SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888,
                                    SDL_TEXTUREACCESS_STREAMING, width, height);
    extern Uint32 myPixels;

    //SDL_UpdateTexture(sdlTexture, NULL, myPixels, width * sizeof (Uint32)); non functional
    //quick tip, SDL_VideoInfo has been replaced by SDL_GetRendererINfo() and SDL_GetRenderrDriverInfo()
    //** WARNING ** NONE OF THIS IS FUNCTIONAL UNTIL FURTHER TESTING IS COMMITED
}

void display_func() {
    for (Game *game : games) {
        glClear(GL_COLOR_BUFFER_BIT);
        game->my_display_func();
    }
    glutPostRedisplay();
}




void load_sprite(const std::string& file_path){

}

void load_background(const std::string& file_path){

}