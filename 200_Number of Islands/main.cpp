//
//  main.cpp
//  200_Number of Islands
//
//  Created by Colin on 04/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, const int rowCount, const int colCount) {
    
    grid[i][j] = '0';
    if(i > 0 && grid[i - 1][j] == '1')
        dfs(grid, i - 1, j, rowCount, colCount);
    if(i < rowCount - 1 && grid[i + 1][j] == '1')
        dfs(grid, i + 1, j, rowCount, colCount);
    if(j > 0 && grid[i][j - 1] == '1')
        dfs(grid, i, j - 1, rowCount, colCount);
    if(j < colCount - 1 && grid[i][j + 1] == '1')
        dfs(grid, i, j + 1, rowCount, colCount);
    return;
}

int numIslands(vector<vector<char>>& grid) {
    int rowCount = grid.size();
    if(rowCount == 0)
        return 0;
    int colCount = grid[0].size();
    int count = 0;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            if(grid[i][j] == '1') {
                ++count;
                dfs(grid, i, j, rowCount, colCount);
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout << numIslands(grid) << endl;
    return 0;
}
