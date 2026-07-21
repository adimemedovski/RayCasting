#include <SDL2/SDL.h>
#include <iostream>
#include <stddef.h>
#include "vectors.hpp"
#include "mapTop.hpp"
#include "userInput.hpp"
#include "circle.hpp"



int main(int argc, char* argv[]) {

    static SDL_Window* window = SDL_CreateWindow(
        "Raycasting in C++",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        2000, 1800,
        SDL_WINDOW_SHOWN
        );


    static SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
   
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << "\n";
        return 1;
    }


    SDL_Color COLOR_IDK = {200, 100, 200, 250};
    
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << "\n";
        SDL_Quit();
        return 1;
    }
    
    MapTop grid = MapTop(renderer, 2000, 1800, 200);
    //Player player = {0, 0, 45};

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        
        //userInput(&event, x, y);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        
        SDL_SetRenderDrawColor(renderer, COLOR_IDK.r, COLOR_IDK.g,
                COLOR_IDK.b, COLOR_IDK.b);

        SDL_RenderFillCircle(renderer, 100, 100, 100);
         
        grid.drawGrid(COLOR_IDK);     
        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
