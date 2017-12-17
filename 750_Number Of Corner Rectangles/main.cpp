//
//  main.cpp
//  750_Number Of Corner Rectangles
//
//  Created by Colin on 16/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int countCornerRectangles(vector<vector<int>>& grid) {
    int rowCount = grid.size();
    if(rowCount < 2)
        return 0;
    int colCount = grid[0].size();
    if(colCount < 2)
        return 0;
    int count = 0;
    for(int j = 0; j <= colCount - 1; ++j) {
        for(int k = j + 1; k < colCount; ++k) {
            int currentCount = 0;
            for(int i = 0; i < rowCount; ++i) {
                if(grid[i][j] == 1 && grid[i][k] == 1)
                    ++currentCount;
            }
            count += currentCount * (currentCount - 1) / 2;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
