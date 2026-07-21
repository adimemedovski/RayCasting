#include <SDL2/SDL.h>
#include <iostream>
#include <stddef.h>

typedef struct {
    double x1;
    double y1;
    double x2;
    double y2;
    size_t fov; // in degrees.
} Player;

typedef struct {
    double x;
    double y;
} Direction;

typedef struct {
    double x;
    double y;
} Camera;

void drawDirectionVector(SDL_Renderer *renderer, SDL_Color color, Player player) {
    double x2 = player.x2 - player.x1;
    double y2 = player.y2 - player.y1;
    
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, player.x1, player.y1, x2, y2);
}


