//
//  main.cpp
//  54_Spiral_Matrix
//
//  Created by Colin on 16/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rowCount = matrix.size();
    vector<int> res;
    if(rowCount == 0) {
        return res;
    }
    int colCount = matrix[0].size();
    vector<vector<bool>> checked(rowCount, vector<bool> (colCount, false));
    int i = 0, j = 0;
    bool valid = true;
    while(valid) {
        valid = false;
        // right
        while(j < colCount && !checked[i][j]) {
            valid = true;
            checked[i][j] = true;
            res.push_back(matrix[i][j]);
            ++j;
        }
        --j;
        ++i;
        while(i < rowCount && !checked[i][j]) {
            valid = true;
            checked[i][j] = true;
            res.push_back(matrix[i][j]);
            ++i;
        }
        --i;
        --j;
        while(j >= 0 && !checked[i][j]) {
            valid = true;
            checked[i][j] = true;
            res.push_back(matrix[i][j]);
            --j;
        }
        ++j;
        --i;
        while(i >=0 && !checked[i][j]) {
            valid = true;
            checked[i][j] = true;
            res.push_back(matrix[i][j]);
            --i;
        }
        ++i;
        ++j;
    }
    return res;
}


int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6}, {7,8,9}};
    auto res = spiralOrder(matrix);
    for(auto ele : res) {
        cout << ele << " " ;
    }
    cout << endl;
    return 0;
}
