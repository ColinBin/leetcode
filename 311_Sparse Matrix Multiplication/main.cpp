//
//  main.cpp
//  311_Sparse Matrix Multiplication
//
//  Created by Colin on 01/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int m = A.size(), n = A[0].size(), p = B[0].size();
    vector<vector<int>> res(m, vector<int> (p, 0));
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(A[i][j] != 0) {
                for(int k = 0; k < p; ++k) {
                    if(B[j][k] != 0)
                        res[i][k] += A[i][j] * B[j][k];
                }
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
