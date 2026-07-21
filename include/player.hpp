#include <SDL2/SDL.h>
#include <iostream>
#include <stddef.h>

typedef struct {
    double x1;
    double y1;
    double x2;
    double y2;
    size_t fov; // in degrees.
    double angle;
} Player;

typedef struct {
    double x;
    double y;
} Direction;

typedef struct {
    double x;
    double y;
} Camera;

static double toRadiansOne(double degrees) {
    return (double) degrees * ((double) std::numbers::pi / 180.0); 
}

void drawDirectionVector(SDL_Renderer *renderer, SDL_Color color, Player player) {
    double x2 = player.x2 + std::cos(toRadiansOne(player.angle)) * 300;
    double y2 = player.y2 + std::sin(toRadiansOne(player.angle)) * 300;
     
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, player.x1, player.y1, x2, y2);
}


