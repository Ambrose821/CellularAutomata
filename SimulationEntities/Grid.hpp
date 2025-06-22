#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
using namespace std;

class Grid{ 

    public:
        Grid(int width, int height, int cellSize): rows(height/cellSize),columns(width/cellSize),cellSize(cellSize), cells(rows,vector<int>(columns,0)){};

        void Draw();
        void RandomInit(); 
        void Update();

       



        private:
            int rows;
            int columns;
            int cellSize;
            vector<vector<int>> cells; 
             //Check if a neighbor is within the bounds of grid
            bool isSafePosition(int row, int col);
            int checkNeighbors(int row,int col,vector<vector<int>> grivPrevState);
            bool isAlive(int liveNeighbors,int currentState);

};
 

#endif