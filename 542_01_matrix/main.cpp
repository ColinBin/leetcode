//
//  main.cpp
//  542_01_matrix
//
//  Created by Colin on 09/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//
// status: AC, but other solutions exist (BFS, DFS)
#include <iostream>
#include <vector>

using std::cout; using std::endl;
using std::vector; using std::min;
// DP solution
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    int rowCount = matrix.size();
    int colCount = matrix[0].size();
    // the maximum distance in the matrix is less than rowCount + colCount;
    vector<vector<int>> distance(rowCount, vector<int> (colCount, rowCount + colCount));
    // update the distance table top-down & left-right
    // say the shortest path for 0 to i is p, the top-down & left-right scan will optimize the any subpath of p that has direction down or right
    // the bottom-up & right-left scan will optimize any subpath of p that has direction up or left
    for(int i = 0; i < rowCount; ++i){
        for(int j = 0; j < colCount; ++j) {
            if(matrix[i][j] == 0)
                distance[i][j] = 0;
            else {
                if(i > 0) distance[i][j] = min(distance[i][j], distance[i - 1][j] + 1);
                if(j > 0) distance[i][j] = min(distance[i][j], distance[i][j - 1] + 1);
            }
        }
    }
    // update the distance table bottom-up & right-left
    for(int i = rowCount - 1; i >= 0; --i) {
        for(int j = colCount - 1; j >= 0; --j) {
            if(i < rowCount - 1) distance[i][j] = min(distance[i][j], distance[i + 1][j] + 1);
            if(j < colCount - 1) distance[i][j] = min(distance[i][j], distance[i][j + 1] + 1);
        }
    }
    
    return distance;
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{1,1,1},{0,1,1},{0,0,0}};
    auto distance = updateMatrix(matrix);
    for(auto v : distance) {
        for(auto ele : v) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
