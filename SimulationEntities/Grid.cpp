#include "Grid.hpp"
#include <raylib.h>
#include <iostream>
using namespace std;
void  Grid::Draw()
{
    
    for(int i =0; i <this->rows; i++){
        for(int j =0; j<this->columns; j++){
         
            Color color = cells[i][j] ? Color{0,255,0,255} : BLACK;
            if(cells[i][j]==1){
            DrawRectangle(j*this->cellSize,i*this->cellSize,this->cellSize,this->cellSize,color);
            }
        }
    }
}


void Grid:: Update(){
 
    for(int i =0; i < this->rows; i++){
      for(int j =0; j< this->columns;j++){
        int liveNeighbors = checkNeighbors(i,j,cells);
        this->nextState[i][j] = isAlive(liveNeighbors,cells[i][j]) ? 1 :0;

      }
    }
    cells.swap(nextState);

}
bool Grid::isSafePosition(int row,int col){
  return(row >= 0 && row< this->rows && col >=0 and col< this->columns);
}

int Grid::checkNeighbors(int row, int col,vector<vector<int>> gridPrevState){
    int liveNeighbors =0;
    
    //Above Neighbors
    if(isSafePosition(row-1,col-1)){
      if(gridPrevState[row-1][col-1] == 1){
      liveNeighbors +=1;
      }
    }
    if(isSafePosition(row-1,col)){
      if(gridPrevState[row-1][col] == 1){
      liveNeighbors +=1;
      }
    }
    if(isSafePosition(row-1,col+1)){
      if(gridPrevState[row-1][col+1] == 1){
      liveNeighbors +=1;
      } 
    }
    //Below Neighbors
    if(isSafePosition(row+1,col-1)){
      if(gridPrevState[row+1][col-1] == 1){
      liveNeighbors +=1;
      } 
    }
      if(isSafePosition(row+1,col)){
      if(gridPrevState[row+1][col] == 1){
      liveNeighbors +=1;
      } 
    }
      if(isSafePosition(row+1,col+1)){
      if(gridPrevState[row+1][col+1] == 1){
      liveNeighbors +=1;
      } 
    }

    //Horizontal Neighbors

      if(isSafePosition(row,col-1)){
      if(gridPrevState[row][col-1] == 1){
      liveNeighbors +=1;
      } 
    }

      if(isSafePosition(row,col+1)){
      if(gridPrevState[row][col+1] == 1){
      liveNeighbors +=1;
      } 
    }
    return liveNeighbors;
}

bool Grid::isAlive(int liveNeighbors,int currentState){

  //1. Any cell with less than 2 neighbors dies or stays dead(result of underpopulation)
  if(liveNeighbors<2){
    return false;
  }
  //2. Any live cell with 2 or 3 live neighbors (as if stable population)
  if(liveNeighbors ==2){
    if(currentState ==0){
      return false;
    }else{
      return true;
    }
  }
  //2 and 3. Any cell with exactly three neighbors is alive, whether it was dead or alive previously
  if(liveNeighbors ==3){
    return true;

  }
  //3. Any cell with more than 3 live neighbors dies or stays dead (result of overpopulation)
  if(liveNeighbors>3){
    return false;
  }
  
  return false; //Not reachable but will satisfy compiler
}
void Grid::RandomInit(){
  for(int i =0; i <this->rows; i++){
    for(int j=0; j<this->columns; j++){
      this->cells[i][j] = rand() % 2 ;
      
    }
  }
  
} 