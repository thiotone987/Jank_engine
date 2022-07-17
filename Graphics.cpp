//
// Created by Jacob Friedman & Cary Chun on 5/26/22.
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

int start_special_graphics(int *argc, char *argv[]){
    //const char* title = "help";
    bool state_flag = true;
    SDL_Window *sdlWindow;
    SDL_GLContext maincontext;
    SDL_DisplayMode currentMode;
    SDL_Event event;
    SDL_Surface *gScreenSurface;
    std::string test_image_1 = "7c43b260a834c4ce7486d7bcc10876de1648757877_full.png";
    int w = 100,h = 200;
    //SDL_Surface* gScreenSurface;

    int defHeight = 240;
    int defWidth = 320;

    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

/* Turn on double buffering with a 24bit Z buffer.
 * You may need to change this to 16 or 32 for your system */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

    sdlWindow = SDL_CreateWindow("YIKES", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                 1600, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    maincontext = SDL_GL_CreateContext(sdlWindow);

    //fights screen tear by syncing to vert refresh rate
    //SDL_GLContext help = SDL_GL_CreateContext(sdlWindow);
    SDL_GL_SetSwapInterval(1);

    //glClearColor(1.0, 0.0, 0.0, 1.0);
    //glClear(GL_COLOR_BUFFER_BIT);

    //SDL_GL_SwapWindow(sdlWindow);

    //idk if this needs to be here
    glutInit(argc, argv);

    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0.f, 0.f, 640, 480);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, 640, 480, 0.0, 1.0, -1.0);

    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();

    glClearColor(0.f, 0.f, 0.f, 1.f);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);

    SDL_Surface *sur = IMG_Load("weeb.png");

    if(sur == NULL){
        printf("Yikes chief, no estambien");
        return 1;
    }

    GLuint txID = 0;
    glGenTextures(1, &txID);
    glBindTexture(GL_TEXTURE_2D, txID);

    //something down here has to be off
    int mode = GL_RGB;
    if(sur->format->BytesPerPixel == 4)
        mode = GL_RGBA;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //GLenum error1 = glGetError();

    glTexImage2D(GL_TEXTURE_2D, 0, mode, sur->w, sur->h, 0, mode, GL_UNSIGNED_BYTE, sur->pixels);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    call_renderer(txID, sur->w, sur->h, sdlWindow);

    GLenum error = glGetError();

    SDL_Delay(200);

    if( error != GL_NO_ERROR )
    {
        printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
    }

    //load_sprite(test_image_1, gScreenSurface);

    //SDL_UpdateWindowSurface(sdlWindow);

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
        //glBindTexture(GL_TEXTURE_2D, NULL);
    }

    int dispIndex = 0;
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

void call_renderer(GLuint &txID, GLfloat w, GLfloat h, SDL_Window *pog){
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(40.0f, 40.0f, 0.0f);
    glBindTexture(GL_TEXTURE_2D, txID);

    glBegin(GL_QUADS);
        glTexCoord2f(0.f, 0.f); glVertex2f(0.f, 0.f);
        glTexCoord2f(1.f, 0.f); glVertex2f(w, 0.f);
        glTexCoord2f(0.f, 0.f); glVertex2f(w, h);
        glTexCoord2f(0.f, 0.f); glVertex2f(0.f, h);
        glEnd();
        SDL_GL_SwapWindow(pog);
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
        //game->my_display_func();
    }
    glutPostRedisplay();
}




SDL_Surface* load_sprite(const std::string& file_path, SDL_Surface *gScreen){
    //NEVERMIND THIS IS IMPORTANT WTF?
    //I am not gonna risk global variables for gScreenSurface
    //** WARNING FOR IMAGE LOADING USE IMG_LOAD() **
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = IMG_Load(file_path.c_str());

    if(loadedSurface == NULL){
        printf("Zoinks surface %s failed again! SDL_image Error: %s\n", file_path.c_str() ,IMG_GetError());
    }
    else{
        optimizedSurface = SDL_ConvertSurface(loadedSurface , gScreen->format, 0);
        if(optimizedSurface == NULL){
            printf("Damn U got a fat image %s! SDL_image Error: %s\n", file_path.c_str(), IMG_GetError());
        }
        SDL_FreeSurface(loadedSurface);
    }
    return optimizedSurface;
}

void load_background(const std::string& file_path){

}