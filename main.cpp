


#include <iostream>
#include<raylib.h>
using namespace std;

int main() {

    cout<<"Loading Game of Life";
    const int screen_width=800;
    const int screen_height=800;

    int FPS = 12;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width,screen_height,"Ambrose's Game of Life");

    SetTargetFPS(FPS); //Lower Fps to properly visualize the simulation
    while(WindowShouldClose()==false){
        BeginDrawing();
        ClearBackground({255,0,0,255});
        //1. Event Handling


        //2. Update State

        //3. Draw Graphics 
        //Draw Graphics
        EndDrawing();
        
    }
    CloseWindow();
}
