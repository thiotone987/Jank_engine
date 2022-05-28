//
// Created by Jacob Friedman on 5/26/22.
//

#include "Graphics.h"
#include <cmath>


void start_graphics(int* argcp, char* argv[]) {
    glutInit(argcp, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(display_func);
    glutMainLoop();
}

void display_func()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.5f, 0.3f);
    display_objects();
    glFlush();
}

void polar_to_cartesian(GLdouble *output, GLdouble radius, GLdouble radians) {
    output[0] = radius*std::cos(radians);
    output[1] = radius*std::sin(radians);
}

void *transform(GLdouble *coords, GLdouble x_shift, GLdouble y_shift) {
    coords[0] += x_shift;
    coords[1] += y_shift;
}

void load_regular_polygon(GLdouble num_sides, GLdouble side_len, GLdouble x, GLdouble y) {
    glBegin(GL_POLYGON);
    //glVertex2f();
    GLdouble center_to_vertex = std::abs(side_len / (2 * std::sin(180.0 / num_sides)));
    auto *coords = new GLdouble[2];
    for (int i = 0; i < num_sides; i++) {
        polar_to_cartesian(coords, center_to_vertex,
                           (2*M_PI/ num_sides)*i);
        transform(coords, x, y);
        glVertex2dv(coords);
    }
    glEnd();
    glFlush();
    delete[] coords;
}

void display_objects() {
    for (Object *object : objects) {
        load_regular_polygon(4, 0.2, object->get_position().get_x(), object->get_position().get_y());
    }
}
