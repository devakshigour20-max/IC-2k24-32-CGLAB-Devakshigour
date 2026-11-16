#include <SDL.h>

// Midpoint Circle Algorithm
void drawCircle(SDL_Renderer* r, int xc, int yc, int radius)
{
    int x = 0, y = radius, d = 1 - radius;   // d = decision parameter
    while (x <= y)
    {
        // ek point se 8 points (symmetry)
        SDL_RenderDrawPoint(r, xc + x, yc + y);
        SDL_RenderDrawPoint(r, xc - x, yc + y);
        SDL_RenderDrawPoint(r, xc + x, yc - y);
        SDL_RenderDrawPoint(r, xc - x, yc - y);
        SDL_RenderDrawPoint(r, xc + y, yc + x);
        SDL_RenderDrawPoint(r, xc - y, yc + x);
        SDL_RenderDrawPoint(r, xc + y, yc - x);
        SDL_RenderDrawPoint(r, xc - y, yc - x);

        x++;
        if (d < 0)
            d += 2 * x + 1;                  
        else
        {
            y--;                             
            d += 2 * (x - y) + 1;
        }
    }
}

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);                                    
    SDL_Window* window = SDL_CreateWindow("Basic Shapes", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 900, 650, SDL_WINDOW_SHOWN);
    SDL_Renderer* r = SDL_CreateRenderer(window, -1, 0);        // drawing tool

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);              // white background
    SDL_RenderClear(r);

    SDL_SetRenderDrawColor(r, 0, 0, 255, 255);                  // blue
    SDL_RenderDrawLine(r, 100, 130, 350, 130);                  // line

    SDL_SetRenderDrawColor(r, 255, 0, 0, 255);                  // red
    drawCircle(r, 650, 130, 70);                                // circle

    SDL_SetRenderDrawColor(r, 0, 150, 0, 255);                  // green
    SDL_Rect rect = {150, 300, 220, 140};                       // x, y, width, height
    SDL_RenderDrawRect(r, &rect);                               // rectangle

    SDL_SetRenderDrawColor(r, 150, 0, 150, 255);                // purple
    SDL_RenderDrawLine(r, 550, 440, 680, 280);                  // triangle: 3 lines
    SDL_RenderDrawLine(r, 680, 280, 810, 440);
    SDL_RenderDrawLine(r, 810, 440, 550, 440);

    SDL_RenderPresent(r);                                       

    SDL_Event e;
    while (SDL_WaitEvent(&e) && e.type != SDL_QUIT);            
    
    SDL_Quit();
    return 0;
}
