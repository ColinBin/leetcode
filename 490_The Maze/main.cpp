//
//  main.cpp
//  490_The Maze
//
//  Created by Colin on 07/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int rowCount = maze.size(), colCount = maze[0].size();
    vector<vector<bool>> checked(rowCount, vector<bool> (colCount, false));
    checked[start[0]][start[1]] = true;
    queue<pair<int, int>> q;
    q.push({start[0], start[1]});
    while(!q.empty()) {
        auto current = q.front();
        q.pop();
        for(const auto &direction : directions) {
            int inew = current.first + direction.first, jnew = current.second + direction.second;
            while(inew >= 0 && inew < rowCount && jnew >= 0 && jnew < colCount && maze[inew][jnew] == 0) {
                inew += direction.first;
                jnew += direction.second;
            }
            inew -= direction.first;
            jnew -= direction.second;
            if(checked[inew][jnew] != true) {
                if(inew == destination[0] && jnew == destination[1])
                    return true;
                q.push(make_pair(inew, jnew));
                checked[inew][jnew] = true;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
