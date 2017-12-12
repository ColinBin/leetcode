//
//  main.cpp
//  256_Paint House
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minCost(vector<vector<int>>& costs) {
    int numHouse = costs.size();
    if(numHouse == 0)
        return 0;
    vector<vector<int>> dp(3, vector<int> (numHouse + 1, 0));
    for(int i = 1; i <= numHouse; ++i) {
        dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + costs[i - 1][0];
        dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + costs[i - 1][1];
        dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + costs[i - 1][2];
    }
    return min(dp[0][numHouse], min(dp[1][numHouse], dp[2][numHouse]));
}

int main(int argc, const char * argv[]) {

    return 0;
}
