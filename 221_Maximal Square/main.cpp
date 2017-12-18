//
//  main.cpp
//  221_Maximal Square
//
//  Created by Colin on 17/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int rowCount = matrix.size();
    if(rowCount == 0)
        return 0;
    int colCount = matrix[0].size();
    vector<int> height(colCount, 0);
    int maxWidth = 0;
    for(int i = 0; i < rowCount; ++i) {
        int widthCount = 0;
        for(int j = 0; j < colCount; ++j) {
            if(matrix[i][j] == '1') {
                ++height[j];
            } else {
                height[j] = 0;
            }
            if(height[j] > maxWidth) {
                ++widthCount;
                if(widthCount > maxWidth) {
                    maxWidth = widthCount;
                    widthCount = 0;
                }
            } else {
                widthCount = 0;
            }
        }
    }
    return maxWidth * maxWidth;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
