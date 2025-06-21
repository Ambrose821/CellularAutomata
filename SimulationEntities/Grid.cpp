#include "Grid.hpp"
#include <raylib.h>
void  Grid::Draw()

{
    for(int i =0; i <this->rows; i++){
        for(int j =0; j<this->columns; j++){
             if(this->cells[i][j] == 1){
               Color color = cells[i][j] ? Color{0,255,0,255} : BLACK;
             }
             Color color = j%2 ==0 && i%2 ==0 ? Color{0,255,0,255} : BLACK;
                DrawRectangle(j*this->cellSize,i*this->cellSize,this->cellSize,this->cellSize,color);
        }
    }
}

bool Grid::isSafePosition(int row,int col)
{
  return(row >= 0 && row< this->rows && col >=0 and col< this->columns);
}
int Grid::checkLife(int row, int col){
    int liveNeighbors =0;
    
    //Above Neighbors
    if(isSafePosition(row-1,col-1)){
      if(cells[row-1][col-1] == 1){
      liveNeighbors +=1;
      }
    }
    if(isSafePosition(row-1,col)){
      if(cells[row-1][col] == 1){
      liveNeighbors +=1;
      }
    }
    if(isSafePosition(row-1,col+1)){
      if(cells[row-1][col+1] == 1){
      liveNeighbors +=1;
      } 
    }
    //Below Neighbors
    if(isSafePosition(row+1,col-1)){
      if(cells[row+1][col-1] == 1){
      liveNeighbors +=1;
      } 
    }
      if(isSafePosition(row+1,col)){
      if(cells[row+1][col] == 1){
      liveNeighbors +=1;
      } 
    }
      if(isSafePosition(row+1,col+1)){
      if(cells[row+1][col+1] == 1){
      liveNeighbors +=1;
      } 
    }

    //Horizontal Neighbors

      if(isSafePosition(row,col-1)){
      if(cells[row][col-1] == 1){
      liveNeighbors +=1;
      } 
    }

      if(isSafePosition(row,col+1)){
      if(cells[row][col+1] == 1){
      liveNeighbors +=1;
      } 
    }
    return liveNeighbors;
}