/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <set>

#define ROW 5
#define COL 5

void visitIsland(int grid[ROW][COL], int i, int j, int& size)
{
    if (i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] != 1)
    {
        return;
    }
    
    grid[i][j] = 2;
    size++;
    
    visitIsland(grid, i - 1, j, size);
    visitIsland(grid, i + 1, j, size);
    visitIsland(grid, i, j - 1, size);
    visitIsland(grid, i, j + 1, size);
}

int max(int x, int y)
{
    return (x >= y) ? x : y;    
}

int getNumOfIslands(int grid[ROW][COL], int& maxIslandSize)
{
    int numOfIslands = 0;
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (grid[i][j] == 1)
            {
                int size = 0;
                visitIsland(grid, i, j, size);
                maxIslandSize = max(size, maxIslandSize);
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
                     
    
    int maxIslandSize = 0;
    int numOfIslands = getNumOfIslands(grid, maxIslandSize);
    std::cout << "numOfIslands - " << numOfIslands << std::endl;
    std::cout << "maxIslandSize - " << maxIslandSize;
    return 0;
}
