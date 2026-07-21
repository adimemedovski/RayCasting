#include <SDL2/SDL.h>
#include <iostream>
#include <stddef.h>

typedef struct {
    double x;
    double y;
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
