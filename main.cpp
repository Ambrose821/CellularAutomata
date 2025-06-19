


#include <iostream>
#include<raylib.h>
using namespace std;

int main() {

    cout<<"Loading Game of Life";
    const int screen_width=800;
    const int screen_height=800;
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width,screen_height,"Ambrose's Game of Life");
    SetTargetFPS(60);
    while(WindowShouldClose()==false){
        BeginDrawing();
        ClearBackground(BLACK);

        //1 Event Handling


        //2 Perform Updates


        //Draw Graphics
        EndDrawing();
        
    }
    CloseWindow();
}
