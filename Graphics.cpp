//
// Created by Jacob Friedman on 5/26/22.
//

#include "Graphics.h"
#include <cmath>

std::map<GLint, void (*)()> windowIDs_to_display_funcs;

void start_graphics(int* argc_p, char* argv[]){
    //glutInit(argc_p, argv);

    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    GLint WindowID1 = glutCreateWindow("Hello world!");
    glutSetWindow(WindowID1);
    glutDisplayFunc(display_func);
    windowIDs_to_display_funcs.emplace(WindowID1, &display_func_1);

    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    GLint WindowID2 = glutCreateWindow("Hello!");
    glutSetWindow(WindowID2);
    glutPositionWindow(0, 0);
    glutDisplayFunc(display_func);
    windowIDs_to_display_funcs.emplace(WindowID2, &display_func_2);


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
        SDL_Log("Display mode dun work bruh", dispIndex, SDL_GetError());
    }
    else{
        SDL_Log("Display #%d: current display mode is %dx%dpx @ %dhz.", dispIndex, currentMode.w, currentMode.h, currentMode.refresh_rate);
    }

    if(vidDriver == NULL){
        SDL_Log("No Video Driver? NO HAPPINESS", SDL_GetError());
    }
    else{
        SDL_Log("Current Video Driver:", vidDriver);
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
    for (auto [windowID, window_display_func] : windowIDs_to_display_funcs) {
        glutSetWindow(windowID);
        window_display_func();
    }
    glutSetWindow(windowIDs_to_display_funcs.begin()->first);
    glutPostRedisplay();
}

void display_func_1()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.5f, 0.3f);
    load_objects();
    glutSwapBuffers();
}
void display_func_2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5f, 0.5f, 0.3f);
    load_objects();
    glutSwapBuffers();
}


void load_regular_polygon(GLdouble num_sides, GLdouble side_len, const PhysicsVector& center_coords) {
    glBegin(GL_POLYGON);
    //glVertex2f();
    const GLdouble center_vertex_dist = std::abs(side_len / (2 * std::sin(180.0 / num_sides)));
    for (int i = 0; i < num_sides; i++) {
        PhysicsVector point_coords =
                PhysicsVector::construct_polar(center_vertex_dist,(2*M_PI/num_sides)*i, METERS)
                + center_coords;
        glVertex2dv(point_coords.as_glvector());
    }
    glEnd();
}

void load_objects() {
    for (Object *object : objects) {
        load_regular_polygon(4, 0.2, object->get_position());
    }
}

void load_sprite(std::string file_path){

}

void load_background(std::string file_path){

}