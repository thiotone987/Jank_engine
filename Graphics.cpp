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

int start_special_graphics(int* argc, char* argv[]){
    //const char* title = "help";
    bool state_flag = true;
    SDL_Window *sdlWindow;
    SDL_GLContext maincontext;
    SDL_DisplayMode currentMode;
    SDL_Event event;

    int defHeight = 240;
    int defWidth = 320;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

/* Turn on double buffering with a 24bit Z buffer.
 * You may need to change this to 16 or 32 for your system */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

    sdlWindow = SDL_CreateWindow("YIKES", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 1600, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    maincontext = SDL_GL_CreateContext(sdlWindow);

    //fights screen tear by syncing to vert refresh rate
    SDL_GL_SetSwapInterval(1);

    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    SDL_GL_SwapWindow(sdlWindow);

    SDL_Delay(200);

    if(sdlWindow == NULL){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return 3;
    }
    else{
        while(state_flag){
            //draw some shit
            while(SDL_PollEvent(&event) != 0){
                if(event.type == SDL_QUIT){
                    std::cout << "haha get stick bugged" << std::endl;
                    state_flag = false;
                }
            }
        }
    }

    int dispIndex;
    int bpp = 0;

    int If_this_is_not_zero_we_have_issues = SDL_GetCurrentDisplayMode(dispIndex, &currentMode);
    const char* vidDriver = SDL_GetCurrentVideoDriver();

    if(If_this_is_not_zero_we_have_issues != 0){
        SDL_Log("Display mode dun work bruh (dispIndex: %d) (error: %s)", dispIndex, SDL_GetError());
        return 3;
    }
    else{
        SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", dispIndex, currentMode.w, currentMode.h, currentMode.refresh_rate);
    }

    if(vidDriver == nullptr){
        SDL_Log("No Video Driver? NO HAPPINESS (error: %s)", SDL_GetError());
        return 3;
    }
    else{
        SDL_Log("Current Video Driver: %s", vidDriver);
    }

    //SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
    //SDL_RenderClear(sdlRenderer);
    //SDL_RenderPresent(sdlRenderer);

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    //SDL_RenderSetLogicalSize(sdlRenderer, defWidth, defHeight);

    //The code below draws a texture to test the efficacy of the renderer

    //SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, 0, 0);
    extern Uint32 myPixels;

    //SDL_Quit();

    //SDL_UpdateTexture(sdlTexture, NULL, myPixels, width * sizeof (Uint32)); non functional
    //quick tip, SDL_VideoInfo has been replaced by SDL_GetRendererINfo() and SDL_GetRenderrDriverInfo()
    //** WARNING ** NONE OF THIS IS FUNCTIONAL UNTIL FURTHER TESTING IS COMMITED
    return 0;
}

int two_SDL_windows(int *argc, char *argv[]){
    SDL_Window *window=SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_OPENGL);
    SDL_Window *window1=SDL_CreateWindow("Window1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_OPENGL);
    SDL_Window *holder;

    //std::vector<SDL_Window> closed_windows[0];
    SDL_Event event;
    bool state_flag = true;

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    SDL_GLContext glContext=SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(SDL_FALSE);

    SDL_GL_MakeCurrent(window, glContext);

    while(state_flag){
        while(SDL_PollEvent(&event)){
            if((event.type==SDL_WINDOWEVENT) && (event.window.event == SDL_WINDOWEVENT_CLOSE)){
                holder = SDL_GetWindowFromID(event.window.windowID);
                if((holder != NULL)){
                    //closed_windows.push_back(holder);
                    SDL_DestroyWindow(holder);
                    holder=NULL;
                }
            }
            if(event.type == SDL_QUIT){
                state_flag = false;
            }
        }

        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }
    return 0;
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