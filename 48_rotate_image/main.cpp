//
//  main.cpp
//  48_rotate_image
//
//  Created by Colin on 11/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using std::vector; using std::cout; using std::endl;

void rotate(vector<vector<int>>& matrix) {
    int dimension = matrix.size();
    if(dimension == 1) {
        return ;
    }
    int rowCount = dimension / 2 - 1;
    int colCount = (dimension - 1) / 2;
    for(int i = 0; i <= rowCount; ++i) {
        for(int j = 0; j <= colCount; ++j) {
            int currentI = i, currentJ = j;
            int nextI = currentJ, nextJ = dimension - 1 - currentI;
            int currentValue = matrix[currentI][currentJ];
            while(true) {
                int newValue = matrix[nextI][nextJ];
                matrix[nextI][nextJ] = currentValue;
                currentValue = newValue;
                currentI = nextI;
                currentJ = nextJ;
                nextI = currentJ;
                nextJ = dimension - 1 -currentI;
                for(auto v : matrix) {
                    for(auto ele : v) {
                        cout << ele << " ";
                    }
                    cout << endl;
                }
                cout << endl;
                if(currentI == i && currentJ == j) {
                    break;
                }
            }
        }
    }
    
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(matrix);
    return 0;
}
