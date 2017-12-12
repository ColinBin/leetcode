//
//  main.cpp
//  265_Paint House II
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minCostII(vector<vector<int>>& costs) {
    int numHouse = costs.size();
    if(numHouse == 0)
        return 0;
    int numColor = costs[0].size();
    int min1 = -1, min2 = -1;
    for(int i = 0; i < numHouse; ++i) {
        for(int color = 0; color < numColor; ++color) {
            if(color != min1) {
                costs[i][color] = (min1 == -1 ? 0 : costs[i - 1][min1]) + costs[i][color];
            } else {
                costs[i][color] = (min2 == -1 ? 0 : costs[i - 1][min2]) + costs[i][color];
            }
        }
        
        min1 = -1;
        min2 = -1;
        for(int j = 0; j < numColor; ++j) {
            if(min1 == -1 || costs[i][j] < costs[i][min1]) {
                min2 = min1;
                min1 = j;
            } else if(min2 == -1 || costs[i][j] < costs[i][min2]) {
                min2 = j;
            }
        }
    }
    return costs[numHouse - 1][min1];
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> costs = {
        {1,3,4,5},
        {2,4,1,6},
        {1,7,2,8},
        {9,1,2,3},
        {4,5,12,6}
    };
    cout << minCostII(costs) << endl;
    return 0;
}
