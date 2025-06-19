


#include <iostream>
#include<raylib.h>
using namespace std;

int main() {

    Color GREY = {29,29,29,255 };
    cout<<"Loading Game of Life";
    const int screen_width=800;
    const int screen_height=800;

    int CELL_SIZE =25;

    int FPS = 12;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width,screen_height,"Ambrose's Game of Life");

    SetTargetFPS(FPS); //Lower Fps to properly visualize the simulation
    while(WindowShouldClose()==false){
      
        //1. Event Handling


        //2. Update State

        //3. Draw Graphics 

        ClearBackground(GREY);
        BeginDrawing();
       
        EndDrawing();
        
    }
    CloseWindow();
}
