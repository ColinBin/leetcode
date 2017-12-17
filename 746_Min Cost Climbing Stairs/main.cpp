//
//  main.cpp
//  746_Min Cost Climbing Stairs
//
//  Created by Colin on 16/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int count = cost.size();
    if(count <= 2)
        return 0;
    cost.push_back(0);
    vector<int> dp(count + 1, 0);
    for(int i = 2; i < count + 1; ++i) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[count];
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
