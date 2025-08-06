


#include <iostream>
#include<raylib.h>
#include "SimulationEntities/Grid.hpp"
using namespace std;

int main() {

    Color GREY = {29,29,29,255 };
    cout<<"Loading Game of Life";
    const int screen_width=800;
    const int screen_height=800;

 

    const int CELL_SIZE =255;
    const int FPS = 12;


    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width,screen_height,"Ambrose's Game of Life");

    SetTargetFPS(FPS); //Lower Fps to properly visualize the simulation


    //init
    Grid grid(GetScreenWidth(),GetScreenHeight(),(GetScreenWidth()/(GetScreenWidth())*3));
    int prev_screen_width = GetScreenWidth();
    int prev_screen_height = GetScreenHeight();

    grid.RandomInit();

    while(WindowShouldClose()==false){


        //0. Detect Window Change
        if(GetScreenHeight() != prev_screen_height || GetScreenWidth() != prev_screen_width ){
            ClearBackground(GREY);
            grid = Grid(GetScreenWidth(),GetScreenHeight(),(GetScreenWidth()/(GetScreenWidth())*3));
            grid.RandomInit();
            prev_screen_width = GetScreenWidth();
            prev_screen_height = GetScreenHeight();
        }
        //1. Event Handling


        //2. Update State
        grid.Update();
        //3. Draw Graphics 

        ClearBackground(GREY);
        BeginDrawing();
        
        grid.Draw();
       
        EndDrawing();
        
    }
    CloseWindow();
}

//  clang++ main.cpp SimulationEntities/*.cpp -std=c++17 -o main -I$(brew --prefix raylib)/include -L$(brew --prefix raylib)/lib -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

//   //clang++ -O3 -flto -std=c++17 -o gol main.cpp SimulationEntities/Grid.cpp -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo




