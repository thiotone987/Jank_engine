//
// Created by Jacob on 5/12/22.
//

#include "TheFirstMover.h"
#include <GLUT/glut.h>


void start_motion() {
    moving = true;
    per_second_movement(0);
}

// per_second_movement needs to take an int because glutTimerFunc always passes an int
void per_second_movement(int) {
    if (moving) {
        // causes per_second_movement to be called every second
        glutTimerFunc(1000, per_second_movement, 0);
    }

    for (Object *obj: objects) {
        obj->move(obj->get_velocity());
    }
    glutPostRedisplay();
}

void end_motion() {
    moving = false;
}
