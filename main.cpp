


#include <iostream>
#include<raylib.h>
using namespace std;

int main() {

    cout<<"Loading Game of Life";
    const int screen_width=1280;
    const int screen_height=800;

    InitWindow(screen_width,screen_height,"Ambrose's Game of Life");

    while(WindowShouldClose()){
        c
    }

}
//  clang++ main.cpp  -std=c++17 -o main \
//   -I$(brew --prefix raylib)/include \
//   -L$(brew --prefix raylib)/lib \
//   -lraylib \
//   -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo