//
//  main.cpp
//  305_Number of Islands II
//
//  Created by Colin on 04/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int getIndex(int indexX, int indexY, int m) {
    return indexX * m + indexY;
}

int getRoot(vector<int> &parents, int index) {
    while(parents[index] != index) {
        parents[index] = parents[parents[index]];
        index = parents[index];
    }
    
    return index;
}

vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
    vector<int> res;
    int positionCount = positions.size();
    if(positionCount == 0 || m == 0 || n == 0)
        return res;
    int count = 0;
    vector<int> parents(m * n, -1);
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int i = 0; i < positionCount; ++i) {
        int positionX = positions[i].first;
        int positionY = positions[i].second;
        int currentIndex = getIndex(positionX, positionY, n);
        // already a part of an island
        if(parents[currentIndex] != -1) {
            res.push_back(count);
            ++i;
            continue;
        }
        ++count;
        parents[currentIndex] = currentIndex;
        for(auto direction : directions) {
            int indexX = positionX + direction.first;
            int indexY = positionY + direction.second;
            int index = getIndex(indexX, indexY, n);
            if(indexX >= 0 && indexX < m && indexY >= 0 && indexY < n && parents[index] != -1) {
                int rootIndex = getRoot(parents, index);
                if(rootIndex != currentIndex) {
                    parents[rootIndex] = currentIndex;
                    --count;
                }
            }
        }
        res.push_back(count);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> positions = {
        {4, 3},
        {2, 3},
        {2, 1},
        {5, 0}
    };
    auto res = numIslands2(6, 5, positions);
    for(auto &ele : res) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
