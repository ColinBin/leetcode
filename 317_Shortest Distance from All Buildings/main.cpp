//
//  main.cpp
//  317_Shortest Distance from All Buildings
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;
vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int shortestDistance(vector<vector<int>>& grid) {
    int rowCount = grid.size();
    if(rowCount == 0) return -1;
    int colCount = grid[0].size();
    
    int minDist = -1;
    auto visitedCount = grid, totalDist = grid;
    int houseCount = 0;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            if(grid[i][j] == 1) {
                queue<pair<int, int>> q;
                int level = 0;
                q.push(make_pair(i, j));
                while(!q.empty()) {
                    ++level;
                    int levelCount = q.size();
                    for(int k = 0; k < levelCount; ++k) {
                        auto currentPos = q.front();
                        q.pop();
                        for(const auto &direction : directions) {
                            int inew = currentPos.first + direction.first;
                            int jnew = currentPos.second + direction.second;
                            if(inew >= 0 && inew < rowCount && jnew >= 0 && jnew < colCount &&
                                grid[inew][jnew] == 0 && visitedCount[inew][jnew] == houseCount) {
                                totalDist[inew][jnew] += level;
                                ++visitedCount[inew][jnew];
                                q.push(make_pair(inew, jnew));
                            }
                        }
                    }
                }
                ++houseCount;
            }
        }
    }
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            if(grid[i][j] == 0 && visitedCount[i][j] == houseCount) {
                if(minDist == -1 || minDist > totalDist[i][j]) {
                    minDist = totalDist[i][j];
                }
            }
        }
    }
    return minDist;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1,0,2,0,1}, {0,0,0,0,0}, {0,0,1,0,0}};
    cout << shortestDistance(grid) << endl;
    return 0;
}

