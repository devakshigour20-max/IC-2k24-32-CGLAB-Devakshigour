#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int gd = DETECT, gm;
    int x1, y1, x2, y2;

    // Input
    cout << "Enter x1 y1: ";
    cin >> x1 >> y1;
    cout << "Enter x2 y2: ";
    cin >> x2 >> y2;

    // DDA calculation
    int dx = x2 - x1;                                  
    int dy = y2 - y1;                                  
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy); 
    float xInc = (float)dx / steps;                    
    float yInc = (float)dy / steps;                    

    cout << "dx = " << dx << ", dy = " << dy << ", steps = " << steps << endl;
    cout << "xInc = " << xInc << ", yInc = " << yInc << endl;

    initgraph(&gd, &gm, (char*)"");                    

    float x = x1, y = y1;                              
    for (int i = 0; i <= steps; i++) {
        putpixel((int)(x + 0.5), (int)(y + 0.5), WHITE); 
        x = x + xInc;
        y = y + yInc;
    }

    getch();                                         
    closegraph();
    return 0;
}
