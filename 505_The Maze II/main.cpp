//
//  main.cpp
//  505_The Maze II
//
//  Created by Colin on 07/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;
struct Entry {
    int i;
    int j;
    int len;
    Entry(int I, int J, int LEN) : i(I), j(J), len(LEN) {  }
};

struct compare{
    bool operator()(const Entry &e1, const Entry &e2) {
        return e1.len > e2.len;
    }
};

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int rowCount = maze.size(), colCount = maze[0].size();
    vector<vector<int>> distance(rowCount, vector<int> (colCount, -1));
    distance[start[0]][start[1]] = -1;
    priority_queue<Entry, vector<Entry>, compare> pq;
    pq.push(Entry(start[0], start[1], 0));
    while(!pq.empty()) {
        Entry current = pq.top();
        pq.pop();
        int i = current.i, j = current.j;
        distance[i][j] = current.len;
        for(const auto &direction : directions) {
            int inew = i + direction.first, jnew = j + direction.second;
            int currentLen = 1;
            while(inew >= 0 && jnew >= 0 && inew < rowCount && jnew < colCount && maze[inew][jnew] == 0) {
                inew += direction.first;
                jnew += direction.second;
                ++currentLen;
            }
            inew -= direction.first;
            jnew -= direction.second;
            --currentLen;
            int totalLen = current.len + currentLen;
            if(distance[inew][jnew] == -1 || totalLen < distance[inew][jnew]) {
                distance[inew][jnew] = totalLen;
                pq.push(Entry(inew, jnew, totalLen));
            }
        }
    }
    return distance[destination[0]][destination[1]];
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4}, end = {4,4};
    cout << shortestDistance(maze, start, end) << endl;
    return 0;
}
