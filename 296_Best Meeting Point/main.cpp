//
//  main.cpp
//  296_Best Meeting Point
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int minTotalDistance(vector<vector<int>>& grid) {
    int rowCount = grid.size();
    if(rowCount == 0) return 0;
    int colCount = grid[0].size();
    vector<int> rowRecord, colRecord;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            if(grid[i][j] == 1) {
                rowRecord.push_back(i);
                colRecord.push_back(j);
            }
        }
    }
    sort(colRecord.begin(), colRecord.end());
    int result = 0;
    int left = 0, right = rowRecord.size() - 1;
    while(left < right) {
        result += rowRecord[right] - rowRecord[left];
        ++left;
        --right;
    }
    left = 0, right = colRecord.size() - 1;
    while(left < right) {
        result += colRecord[right] - colRecord[left];
        ++left;
        --right;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
