//
//  main.cpp
//  59_spiral_matrix_two
//
//  Created by Colin on 16/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int> (n, 0));
    if(n == 0) {
        return res;
    }
    int rowBegin = 0, rowEnd = n - 1, colBegin = 0, colEnd = n - 1;
    int count = 0;
    while(count < n * n) {
        for(int j = colBegin; j <= colEnd; ++j) {
            res[rowBegin][j] = ++count;
        }
        ++rowBegin;
        for(int i = rowBegin; i <= rowEnd; ++i) {
            res[i][colEnd] = ++count;
        }
        --colEnd;
        for(int j = colEnd; j >= colBegin; --j) {
            res[rowEnd][j] = ++count;
        }
        --rowEnd;
        for(int i = rowEnd; i >= rowBegin; --i) {
            res[i][colBegin] = ++count;
        }
        ++colBegin;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    int n = 3;
    auto res = generateMatrix(n);
    for(auto row : res) {
        for(auto ele :row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
