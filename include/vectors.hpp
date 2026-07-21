#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>
#include <numbers>

static double toRadians(double degrees) {
    return (double) degrees * ((double) std::numbers::pi / 180.0); 
}

template<typename T>
class Vector2D {
    private:
        T x1;
        T y1;
        T x2;
        T y2;
        SDL_Renderer *renderer;  
    public:
        Vector2D(SDL_Renderer *renderer, T x1, T y1, T x2, T y2) : 
            x1(x1), y1(y1), 
            x2(x2), y2(y2),
            renderer(renderer)
    {
    }

        void drawVector(SDL_Color color) {
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2); 
        }

        /*
         * Draws a vector relative to x1 and y1.
         */
        void drawVector(SDL_Color color, T x, T y) {
            SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);   
            SDL_RenderDrawLine(renderer, x1, y1, x, y);  
        }

        void drawCircle(SDL_Color color, T radius) {
            double degrees = 0; 
            double radians = 0;

            double xComponent = 0; 
            double yComponent = 0;

            for (size_t i = 0; i < 360; i++) {
                degrees += 1;
                radians = toRadians(degrees);     

                xComponent = x1 + (radius) * (std::cos(radians));
                yComponent = y1 + (radius) * (std::sin(radians)); 
                std::cerr << xComponent << "\n" << yComponent << "\n" << std::endl; 
                drawVector(color, xComponent, yComponent);

            }
        }

        void setPoints(T x1, T y1, T x2, T y2) {
            this -> x1 = x1;
            this -> y1 = y1;
            this -> x2 = x2;
            this -> y2 = y2;
        }





};
