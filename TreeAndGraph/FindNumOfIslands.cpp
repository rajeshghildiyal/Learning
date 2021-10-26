#include <iostream>
#include <set>

#define ROW 5
#define COL 5

void visitIsland(int grid[ROW][COL], int i, int j)
{
    if (i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] != 1)
    {
        return;
    }
    
    // Update value to 2 to avoid separate space to mark a node as visited. 
    grid[i][j] = 2;
    
    // Visit horizontal and vertical neighbors of a node.
    visitIsland(grid, i - 1, j);
    visitIsland(grid, i + 1, j);
    visitIsland(grid, i, j - 1);
    visitIsland(grid, i, j + 1);
}

int getNumOfIslands(int grid[ROW][COL])
{
    int numOfIslands = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (grid[i][j] == 1)
            {
                visitIsland(grid, i, j);
                numOfIslands++;
            }
        }
    }
    return numOfIslands;
}

int main()
{
    int grid[ROW][COL] = { { 1, 1, 0, 0, 0 },
                           { 0, 1, 0, 0, 1 },
                           { 1, 0, 0, 1, 1 },
                           { 0, 0, 0, 0, 0 },
                           { 1, 0, 1, 0, 1 } };
                     
    int numOfIslands = getNumOfIslands(grid);
    std::cout << "numOfIslands - " << numOfIslands;
    return 0;
}
