//
//  main.cpp
//  463_Island Perimeter
//
//  Created by Colin on 24/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<pair<int, int>> directions = {{0, 1},{0, -1}, {1,0}, {-1, 0}};

void dfs(vector<vector<int>> &grid, int i, int j, int &perimiter) {
    int waterCount = 4;
    grid[i][j] = -1;
    for(const auto &direction : directions) {
        int new_i = i + direction.first, new_j = j + direction.second;
        if(new_i >= 0 && new_i < grid.size() && new_j >= 0 && new_j < grid[0].size()) {
            if(grid[new_i][new_j] == -1)
                --waterCount;
            else if(grid[new_i][new_j] == 1) {
                --waterCount;
                dfs(grid, new_i, new_j, perimiter);
            }
        }
    }
    perimiter += waterCount;
    return;
}

int islandPerimeter(vector<vector<int>>& grid) {
    int rowCount = grid.size(), colCount = grid[0].size();
    int perimiter = 0;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            if(grid[i][j] == 1) {
                dfs(grid, i, j, perimiter);
                break;
            }
        }
    }
    return perimiter;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
