//
//  main.cpp
//  361_Bomb Enemy
//
//  Created by Colin on 27/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxKilledEnemies(vector<vector<char>>& grid) {
    int rowCount = grid.size();
    if(rowCount == 0) return 0;
    int colCount = grid[0].size();
    vector<int> colhits(colCount, 0);
    int rowhits = 0;
    int maxKill = 0;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            if(j == 0 || grid[i][j - 1] == 'W') {
                rowhits = 0;
                for(int k = j; k < colCount && grid[i][k] != 'W'; ++k)
                    if(grid[i][k] == 'E')
                        ++rowhits;
            }
            if(i == 0 || grid[i - 1][j] == 'W') {
                colhits[j] = 0;
                for(int k = i; k < rowCount && grid[k][j] != 'W'; ++k)
                    if(grid[k][j] == 'E')
                        ++colhits[j];
            }
            if(grid[i][j] == '0')
                maxKill = max(maxKill, rowhits + colhits[j]);
        }
    }
    return maxKill;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
