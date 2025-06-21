#include "Grid.hpp"
#include <raylib.h>
void  Grid::Draw()

{
    for(int i =0; i <this->rows; i++){
        for(int j =0; j<this->columns; j++){
            
             int liveNeighbors = checkNeighbors(i,j);

             if(this->cells[i][j] == 1){
               Color color = cells[i][j] ? Color{0,255,0,255} : BLACK;
             }
             Color color = j%2 ==0 && i%2 ==0 ? Color{0,255,0,255} : BLACK;
                DrawRectangle(j*this->cellSize,i*this->cellSize,this->cellSize,this->cellSize,color);
        }
    }
}

bool Grid::isSafePosition(int row,int col){
  return(row >= 0 && row< this->rows && col >=0 and col< this->columns);
}

int Grid::checkNeighbors(int row, int col){
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

bool Grid::isAlive(int liveNeighbors,int currentState){

  //1. Any cell with less than 2 neighbors dies or stays dead(result of underpopulation)
  if(liveNeighbors<2){
    return false;
  }
  //2. Any live cell with 2 or 3 live neighbors (as if stable population)
  else if (currentState ==1 && (liveNeighbors ==2 || liveNeighbors ==3)){
    return true;
  }
  //3. Any Live cell with more than 3 live neighbors dies (result of overpopulation)
  else if( currentState ==1 && (liveNeighbors>3)){
    return false;
  }
  //4. Any Dead cell with EXACTLY 3 live neighbors becomes alive (as if reproduction)
  else if(currentState ==0 &&(liveNeighbors ==3)){
    return true;
  }
    
}