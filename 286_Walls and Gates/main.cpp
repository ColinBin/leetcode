//
//  main.cpp
//  286_Walls and Gates
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void wallsAndGates(vector<vector<int>>& rooms) {
    const int EMPTY = INT_MAX;
    const int GATE = 0;
    int rowCount = rooms.size();
    if(rowCount == 0) return;
    int colCount = rooms[0].size();
    queue<pair<int, int>> q;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            if(rooms[i][j] == GATE)
                q.push(make_pair(i, j));
        }
    }
    int level = 0;
    while(!q.empty()) {
        int levelSize = q.size();
        ++level;
        for(int i = 0; i < levelSize; ++i) {
            auto current = q.front();
            q.pop();
            for(const auto &direction: directions) {
                int inew = current.first + direction.first, jnew = current.second + direction.second;
                if(inew >= 0 && inew < rowCount && jnew >= 0 && jnew < colCount && rooms[inew][jnew] == EMPTY) {
                    rooms[inew][jnew] = level;
                    q.push(make_pair(inew, jnew));
                }
            }
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
