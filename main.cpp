


#include <iostream>
#include<raylib.h>
#include "SimulationEntities/Grid.hpp"
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


    //init
    Grid grid(GetScreenWidth(),GetScreenHeight(),GetScreenWidth()/75);
    int prev_screen_width = GetScreenWidth();
    int prev_screen_height = GetScreenHeight();

    while(WindowShouldClose()==false){


        //0. Detect Window Change
        if(GetScreenHeight() != prev_screen_height || GetScreenWidth() != prev_screen_width ){
            grid = Grid(GetScreenWidth(),GetScreenHeight(),GetScreenWidth()/75);
        }
        //1. Event Handling


        //2. Update State

        //3. Draw Graphics 

        ClearBackground(GREY);
        BeginDrawing();
        grid.Draw();
       
        EndDrawing();
        
    }
    CloseWindow();
}
