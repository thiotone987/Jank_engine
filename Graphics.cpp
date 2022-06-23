//
// Created by Jacob Friedman on 5/26/22.
//

#include "Graphics.h"
#include <cmath>

std::map<GLint, void (*)()> windowIDs_to_display_funcs;

void start_graphics(int* argc_p, char* argv[]){
    glutInit(argc_p, argv);

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