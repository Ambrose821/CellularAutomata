#include "Grid.hpp"
#include <raylib.h>
void  Grid::Draw()

{
    for(int i =0; i <this->rows; i++){
        for(int j =0; j<this->columns; j++){
             if(this->cells[i][j] == 1){
               Color color = cells[i][j] ? Color{0,255,0,255} : Color{55,55,55,255};
             }
             Color color = j%2 ==0 && i%2 ==0 ? Color{0,255,0,255} : Color{55,55,55,255};
                DrawRectangle(j*this->cellSize,i*this->cellSize,this->cellSize,this->cellSize,color);
        }
    }
}