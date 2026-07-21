#include <SDL2/SDL.h>
#include <iostream>
#include "userInput.hpp"

void userInput(SDL_Event *event, double &x, double &y) {
    switch (event -> type) {
        case (SDL_KEYDOWN):
            switch (event -> key.keysym.sym) {
                case (SDLK_LEFT):
                    x -= speed;
                    break;
                case (SDLK_RIGHT):
                    x += speed;
                    break;
                case (SDLK_UP):
                    y -= speed;
                    break;
                case (SDLK_DOWN):
                    y += speed;
                    break;
                default:
                    break;
            }
    }
}

