#include <SDL2/SDL.h>
#include <iostream>
#include <stddef.h>

class MapTop {
    private:
        int windowWidth;
        int windowHeight;
        int squareLength;
        SDL_Renderer *renderer;
    public:
        MapTop(SDL_Renderer *renderer, int windowWidth, int windowHeight, int squareLength) :
            renderer(renderer), windowWidth(windowWidth), windowHeight(windowHeight),
            squareLength(squareLength)
    {}

        void drawVector(SDL_Color color, double x1, double y1, 
                double x2, double y2) {
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); 
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
        }

        void drawColumns(size_t columns, SDL_Color color) {
            int x = 0;
            
            for (size_t i = 0; i < columns; i++) {
                drawVector(color, x, 0, x, windowHeight);
                
                x += squareLength;
            }
        }

        void drawRows(size_t rows, SDL_Color color) {
            int y = 0; 
            

            for (size_t i = 0; i < rows; i++) {
                drawVector(color, 0, y, windowWidth, y);
                
                y += squareLength;
            }
        }

        void drawGrid(SDL_Color color) {
            size_t rows = windowHeight / squareLength; 
            size_t columns =  windowWidth / squareLength; 
             
            drawColumns(columns, color); 
            drawRows(rows, color); 
        }
};

