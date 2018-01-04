//
//  main.cpp
//  329_Longest Increasing Path in a Matrix
//
//  Created by Colin on 03/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int helper(const vector<vector<int>> &matrix, vector<vector<int>> &memo, int i, int j) {
    if(memo[i][j] != -1) return memo[i][j];
    int childMax = 0;
    for(const auto &direction : directions) {
        int inew = i + direction.first, jnew = j + direction.second;
        if(inew >= 0 && inew < matrix.size() && jnew >= 0 && jnew < matrix[0].size() && matrix[inew][jnew] > matrix[i][j]) {
            int childPath = helper(matrix, memo, inew, jnew);
            childMax = max(childMax, childPath);
        }
    }
    memo[i][j] = childMax + 1;
    return memo[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int rowCount = matrix.size();
    if(rowCount == 0) return 0;
    int colCount = matrix[0].size();
    vector<vector<int>> memo(rowCount, vector<int> (colCount, -1));
    int maxLen = 0;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            maxLen = max(maxLen, helper(matrix, memo, i, j));
        }
    }
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
