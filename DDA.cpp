#include <SDL.h>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[])
{
    int x1, y1, x2, y2;
    cout << "Enter start point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter end point (x2 y2): ";
    cin >> x2 >> y2;

    // DDA calculation
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));      // jis taraf zyada change, utne steps
    float xInc = (float)dx / steps;         // har step me x kitna badhe
    float yInc = (float)dy / steps;         // har step me y kitna badhe

    cout << "dx = " << dx << ", dy = " << dy << ", steps = " << steps << endl;
    cout << "xInc = " << xInc << ", yInc = " << yInc << endl;

    SDL_Init(SDL_INIT_VIDEO);               // graphics shuru
    SDL_Window* window = SDL_CreateWindow("DDA Line", SDL_WINDOWPOS_CENTERED,
                         SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    SDL_Renderer* r = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(r, 255, 255, 255, 255);   // white background
    SDL_RenderClear(r);
    SDL_SetRenderDrawColor(r, 0, 0, 255, 255);       // blue line

    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++)
    {
        SDL_RenderDrawPoint(r, round(x), round(y));  // pixel plot
        x += xInc;
        y += yInc;
    }

    SDL_RenderPresent(r);                            // screen pe dikhao

    SDL_Event e;
    while (SDL_WaitEvent(&e) && e.type != SDL_QUIT); // window band hone tak ruko

    SDL_Quit();
    return 0;
}
