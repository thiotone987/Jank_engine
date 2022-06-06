//
// Created by Jacob Friedman on 6/5/22.
//

#include "Input.h"

char Input::getKey() {

    char key = NO_KEY;
    //char key = SDLK_DELETE;
    bool modState;
    modState = (SDL_GetModState() == KMOD_LSHIFT || SDL_GetModState() == KMOD_RSHIFT);

    if(currentKeyStates[SDL_SCANCODE_A]) key = 'A';
    if(currentKeyStates[SDL_SCANCODE_B]) key = 'B';
    if(currentKeyStates[SDL_SCANCODE_C]) key = 'C';
    if(currentKeyStates[SDL_SCANCODE_D]) key = 'D';
    if(currentKeyStates[SDL_SCANCODE_E]) key = 'E';
    if(currentKeyStates[SDL_SCANCODE_F]) key = 'F';
    if(currentKeyStates[SDL_SCANCODE_G]) key = 'G';
    if(currentKeyStates[SDL_SCANCODE_H]) key = 'H';
    if(currentKeyStates[SDL_SCANCODE_I]) key = 'I';
    if(currentKeyStates[SDL_SCANCODE_J]) key = 'J';
    if(currentKeyStates[SDL_SCANCODE_K]) key = 'K';
    if(currentKeyStates[SDL_SCANCODE_L]) key = 'L';
    if(currentKeyStates[SDL_SCANCODE_M]) key = 'M';
    if(currentKeyStates[SDL_SCANCODE_N]) key = 'N';
    if(currentKeyStates[SDL_SCANCODE_O]) key = 'O';
    if(currentKeyStates[SDL_SCANCODE_P]) key = 'P';
    if(currentKeyStates[SDL_SCANCODE_Q]) key = 'Q';
    if(currentKeyStates[SDL_SCANCODE_R]) key = 'R';
    if(currentKeyStates[SDL_SCANCODE_S]) key = 'S';
    if(currentKeyStates[SDL_SCANCODE_T]) key = 'T';
    if(currentKeyStates[SDL_SCANCODE_U]) key = 'U';
    if(currentKeyStates[SDL_SCANCODE_V]) key = 'V';
    if(currentKeyStates[SDL_SCANCODE_W]) key = 'W';
    if(currentKeyStates[SDL_SCANCODE_X]) key = 'X';
    if(currentKeyStates[SDL_SCANCODE_Y]) key = 'Y';
    if(currentKeyStates[SDL_SCANCODE_Z]) key = 'Z';

    if(currentKeyStates[SDL_SCANCODE_1] && !modState) key = '1';
    if(currentKeyStates[SDL_SCANCODE_2] && !modState) key = '2';
    if(currentKeyStates[SDL_SCANCODE_3] && !modState) key = '3';
    if(currentKeyStates[SDL_SCANCODE_4] && !modState) key = '4';
    if(currentKeyStates[SDL_SCANCODE_5] && !modState) key = '5';
    if(currentKeyStates[SDL_SCANCODE_6] && !modState) key = '6';
    if(currentKeyStates[SDL_SCANCODE_7] && !modState) key = '7';
    if(currentKeyStates[SDL_SCANCODE_8] && !modState) key = '8';
    if(currentKeyStates[SDL_SCANCODE_9] && !modState) key = '9';
    if(currentKeyStates[SDL_SCANCODE_0] && !modState) key = '0';

    if(currentKeyStates[SDL_SCANCODE_1] && modState) key = '!';
    if(currentKeyStates[SDL_SCANCODE_2] && modState) key = '@';
    if(currentKeyStates[SDL_SCANCODE_3] && modState) key = '#';
    if(currentKeyStates[SDL_SCANCODE_4] && modState) key = '$';
    if(currentKeyStates[SDL_SCANCODE_5] && modState) key = '%';
    if(currentKeyStates[SDL_SCANCODE_6] && modState) key = '^';
    if(currentKeyStates[SDL_SCANCODE_7] && modState) key = '&';
    if(currentKeyStates[SDL_SCANCODE_8] && modState) key = '*';
    if(currentKeyStates[SDL_SCANCODE_9] && modState) key = '(';
    if(currentKeyStates[SDL_SCANCODE_0] && modState) key = ')';

    if(currentKeyStates[SDL_SCANCODE_KP_1] ) key = '1';
    if(currentKeyStates[SDL_SCANCODE_KP_2] ) key = '2';
    if(currentKeyStates[SDL_SCANCODE_KP_3] ) key = '3';
    if(currentKeyStates[SDL_SCANCODE_KP_4] ) key = '4';
    if(currentKeyStates[SDL_SCANCODE_KP_5] ) key = '5';
    if(currentKeyStates[SDL_SCANCODE_KP_6] ) key = '6';
    if(currentKeyStates[SDL_SCANCODE_KP_7] ) key = '7';
    if(currentKeyStates[SDL_SCANCODE_KP_8] ) key = '8';
    if(currentKeyStates[SDL_SCANCODE_KP_9] ) key = '9';
    if(currentKeyStates[SDL_SCANCODE_KP_0] ) key = '0';

    if(currentKeyStates[SDL_SCANCODE_KP_1] && modState) key = '!';
    if(currentKeyStates[SDL_SCANCODE_KP_2] && modState) key = '@';
    if(currentKeyStates[SDL_SCANCODE_KP_3] && modState) key = '#';
    if(currentKeyStates[SDL_SCANCODE_KP_4] && modState) key = '$';
    if(currentKeyStates[SDL_SCANCODE_KP_5] && modState) key = '%';
    if(currentKeyStates[SDL_SCANCODE_KP_6] && modState) key = '^';
    if(currentKeyStates[SDL_SCANCODE_KP_7] && modState) key = '&';
    if(currentKeyStates[SDL_SCANCODE_KP_8] && modState) key = '*';
    if(currentKeyStates[SDL_SCANCODE_KP_9] && modState) key = '(';
    if(currentKeyStates[SDL_SCANCODE_KP_0] && modState) key = ')';

    if(currentKeyStates[SDLK_PLUS]) key = '+';
    if(currentKeyStates[SDL_SCANCODE_KP_PLUS]) key = '+';
    if(currentKeyStates[SDL_SCANCODE_EQUALS] &&  modState) key = '+';

    if(currentKeyStates[SDL_SCANCODE_KP_MINUS]) key = '-';
    if(currentKeyStates[SDL_SCANCODE_MINUS]) key = '-';

    if(currentKeyStates[SDL_SCANCODE_8] && modState) key = '*';
    if(currentKeyStates[SDL_SCANCODE_KP_MULTIPLY]) key = '*';

    if(currentKeyStates[SDL_SCANCODE_KP_DIVIDE]) key = '/';
    if(currentKeyStates[SDL_SCANCODE_SLASH]) key = '/';

    if(currentKeyStates[SDL_SCANCODE_EQUALS] && !modState) key = '=';
    if(currentKeyStates[SDL_SCANCODE_KP_EQUALS]) key = '=';

    if(currentKeyStates[SDL_SCANCODE_SPACE]) key = ' ';
    if(currentKeyStates[SDL_SCANCODE_DOWN])  key = SDL_SCANCODE_DOWN;
    if(currentKeyStates[SDL_SCANCODE_UP])    key = SDL_SCANCODE_UP;
    if(currentKeyStates[SDL_SCANCODE_LEFT])  key = SDL_SCANCODE_LEFT;
    if(currentKeyStates[SDL_SCANCODE_RIGHT]) key = SDL_SCANCODE_RIGHT;

    //Delete Key
    if(currentKeyStates[SDL_SCANCODE_BACKSPACE])  key = SDLK_DELETE;

    //Enter/Return Key
    if(currentKeyStates[SDL_SCANCODE_RETURN])  key = SDLK_RETURN;
    if(currentKeyStates[SDL_SCANCODE_KP_ENTER]) key = SDLK_RETURN;

    //ESC - enter quit state
    if(currentKeyStates[SDL_SCANCODE_ESCAPE]) key = true;

    return key;
}
