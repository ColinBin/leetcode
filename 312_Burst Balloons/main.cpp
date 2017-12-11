//
//  main.cpp
//  312_Burst Balloons
//
//  Created by Colin on 10/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int maxCoins(vector<int>& nums) {
    int numsCount = nums.size();
    if(numsCount == 0)
        return 0;
    else if(numsCount == 1)
        return nums[0];
    vector<vector<int>> dp(numsCount, vector<int> (numsCount, 0));
    dp[0][0] = nums[0] * nums[1];
    dp[numsCount - 1][numsCount - 1] = nums[numsCount - 1] * nums[numsCount - 2];
    for(int i = 1; i < numsCount - 1; ++i) {
        dp[i][i] = nums[i] * nums[i - 1] * nums[i + 1];
    }
    for(int len = 2; len <= numsCount; ++len) {
        for(int i = 0; i <= numsCount - len; ++i) {
            int j = len + i - 1;
            int leftCoin = (i == 0 ? 1 : nums[i - 1]);
            int rightCoin = (j == numsCount - 1 ? 1 : nums[j + 1]);
            // when i < k < j
            for(int k = i + 1; k < j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i][k - 1] + dp[k + 1][j] + nums[k] * leftCoin * rightCoin);
            }
            // when k == i || k == j
            dp[i][j] = max(dp[i][j], dp[i + 1][j] + nums[i] * leftCoin * rightCoin);
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + nums[j] * leftCoin * rightCoin);
        }
    }
    return dp[0][numsCount - 1];
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,1,5,8};
    cout << maxCoins(nums) << endl;
    return 0;
}
