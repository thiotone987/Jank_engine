#include <iostream>
#include <SDL.h>
#include "Object.h"
#include "TheFirstMover.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>


void display_func()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glVertex3f(0.5, 0.0, 0.5);
    glVertex3f(0.5, 0.0, 0.0);
    glVertex3f(0.0, 0.5, 0.0);
    glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}

void start_graphics(int* argcp, char* argv[]) {
    glutInit(argcp, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(display_func);
    glutMainLoop();
}

int main(int argc, char* argv []) {
    start_graphics(&argc, argv);
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    std::cout << "Hello, World!" << std::endl;
    Object obj(PhysicsVector(2, 3), PhysicsVector(1, 2));
    std::cout << "obj: " << obj << std::endl;
    start_motion();
    Object obj2(PhysicsVector(3, 4), PhysicsVector(-5, 10));
    std::cout << "obj2: " << obj2 << std::endl;
    for (int i = 0; i < 10; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "obj: " << obj << std::endl;
        std::cout << "obj2: " << obj2 << std::endl;
    }
    end_motion();
    SDL_Quit();

    return 0;
}