#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
using namespace std;

class Grid{ 

    public:
        Grid(int width, int height, int cellSize);


        private:
        int rows;
        int columns;
        int cellSize;
        vector<vector<int>> cells;

};


#endif