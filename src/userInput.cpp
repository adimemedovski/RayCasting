#include <SDL2/SDL.h>
#include <iostream>
#include "userInput.hpp"

void userInput(SDL_Event *event, double &x, double &y, double &angle) {
    switch (event -> type) {
        case (SDL_KEYDOWN):
            switch (event -> key.keysym.sym) {
                case (SDLK_LEFT):
                    x -= speed;
                    angle = 180; 
                    break;
                case (SDLK_RIGHT):
                    x += speed;
                    angle = 0; 
                    break;
                case (SDLK_UP):
                    y -= speed;
                    angle = -90; 
                    break;
                case (SDLK_DOWN):
                    y += speed;
                    angle = 90;  
                    break;
                case (SDLK_RETURN):
                    angle += 1; // rotates direction vector.
                    break; 
                default:
                    break;
            }
    }
}

