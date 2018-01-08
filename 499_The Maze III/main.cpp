//
//  main.cpp
//  499_The Maze III
//
//  Created by Colin on 07/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

struct Entry {
    int i, j, len;
    string path;
    Entry(int currI, int currJ, int currLen, string currPath) : i(currI), j(currJ), len(currLen), path(currPath) { }
};

struct compare {
    bool operator()(const Entry &e1, const Entry &e2) {
        return e1.len > e2.len || (e1.len == e2.len && e1.path > e2.path);
    }
};

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<char> dirs = {'r', 'l', 'd', 'u'};

string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
    int rowCount = maze.size(), colCount = maze[0].size();
    // fill the hole, and make it a wall
    maze[hole[0]][hole[1]] = 1;
    priority_queue<Entry, vector<Entry>, compare> pq;
    vector<vector<int>> distance(rowCount, vector<int> (colCount, -1));
    pq.push(Entry(ball[0], ball[1], 0, ""));
    int minDist = -1; // should use a negative number to initialize
    string res = "";
    while(!pq.empty()) {
        auto current = pq.top();
        pq.pop();
        int i = current.i, j = current.j;
        int len = current.len;
        for(int index = 0; index < 4; ++index) {
            if(hole[0] == i + directions[index].first && hole[1] == j + directions[index].second) {
                if(current.path.empty() || current.path.back() != dirs[index])
                    current.path += dirs[index];
                if(minDist == -1 || len < minDist) {
                    minDist = len;
                    res = current.path;
                } else if(minDist == len){
                    res = min(res, current.path);
                }
            }
        }
        if(distance[i][j] != -1 && current.len >= distance[i][j])
            continue;
        distance[i][j] = current.len;
        for(int index = 0; index < 4; ++index) {
            int f = directions[index].first, s = directions[index].second;
            int inew = i + f, jnew = j + s;
            int currLen = len + 1;
            string currentPath = current.path;
            while(inew >= 0 && jnew >= 0 && inew < rowCount && jnew < colCount && maze[inew][jnew] == 0) {
                ++currLen;
                inew += f;
                jnew += s;
            }
            currentPath += dirs[index];
            --currLen;
            inew -= f;
            jnew -= s;
            if(distance[inew][jnew] == -1 || currLen < distance[inew][jnew]) {
                pq.push(Entry(inew, jnew, currLen, currentPath));
            }
        }
    }
    return minDist == -1 ? "impossible" : res;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> maze = {{0,0,0},{0,0,0},{0,0,0}};
    vector<int> ball = {0,0}, hole = {1,2};
    cout << findShortestWay(maze, ball, hole) << endl;
    return 0;
}
