//
// Created by Jacob Friedman on 6/6/22.
//

#include "Game.h"
#include "Graphics.h"

// create a window
//

void load_regular_polygon(GLdouble num_sides, GLdouble side_len, const PhysicsVector& center_coords) {
    glBegin(GL_POLYGON);
    const GLdouble center_vertex_dist = std::abs(side_len / (2 * std::sin(180.0 / num_sides)));
    for (int i = 0; i < num_sides; i++) {
        PhysicsVector point_coords =
                PhysicsVector::construct_polar(center_vertex_dist,(2*M_PI/num_sides)*i, METERS)
                + center_coords;
        glVertex2dv(point_coords.as_glvector());
    }
    glEnd();
}

Game::Game(std::vector<Object*>& objects) noexcept : objects(objects) {
    games.push_back(this);
    moving = false;
}

void Game::my_display_func() {
    glutSetWindow(windowID);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.5f, 0.3f);
    for (Object *object : objects) {
        load_regular_polygon(4, 0.2, object->position);
    }
    glutSwapBuffers();
}

void call_per_second_movement(int game_index) {
    games.at(game_index)->per_second_movement(game_index);
}

// per_second_movement needs to take an int because glutTimerFunc always passes an int
void Game::per_second_movement(int game_index) {
    if (moving) {
        // causes per_second_movement to be called every second
        glutTimerFunc(1000, call_per_second_movement, game_index);
    }

    for (Object *obj: objects) {
        obj->move(obj->velocity*SECONDS);
    }
}

void Game::load() {
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    windowID = glutCreateWindow("Hello world!");
    glutSetWindow(windowID);
    glutDisplayFunc(display_func);
}

void Game::run() {
    moving = true;
    int game_index = -1;
    for (int i = 0; i < games.size(); i++) {
        if (games.at(i) == this) {
            game_index = i;
        }
    }
    per_second_movement(game_index);
}

void Game::stop_run() {
    moving = false;
}

void Game::unload() {

}