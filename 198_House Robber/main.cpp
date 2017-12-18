//
//  main.cpp
//  198_House Robber
//
//  Created by Colin on 17/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int numCount = nums.size();
    if(numCount == 0)
        return 0;
    else if(numCount == 1)
        return nums[0];
    vector<int> dp(numCount + 1, 0);
    dp[1] = nums[0];
    for(int i = 2; i <= numCount; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
    }
    return dp[numCount];
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
