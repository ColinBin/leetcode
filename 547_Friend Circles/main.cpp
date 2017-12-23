//
//  main.cpp
//  547_Friend Circles
//
//  Created by Colin on 22/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int findRoot(vector<int> &parent, int index) {
    while(index != parent[index]) {
        parent[index] = parent[parent[index]];
        index = parent[index];
    }
    return index;
}

int findCircleNum(vector<vector<int>>& M) {
    int rowCount = M.size();
    if(rowCount == 0)
        return 0;
    vector<int> parent(rowCount, 0);
    for(int i = 0; i < rowCount; ++i) {
        parent[i] = i;
    }
    int count = rowCount;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = i + 1; j < rowCount; ++j) {
            if(M[i][j] == 1) {
                int root1 = findRoot(parent, i), root2 = findRoot(parent, j);
                if(root1 != root2) {
                    --count;
                    parent[root1] = root2;
                }
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
