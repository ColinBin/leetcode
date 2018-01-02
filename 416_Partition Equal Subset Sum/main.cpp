//
//  main.cpp
//  416_Partition Equal Subset Sum
//
//  Created by Colin on 01/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool canPartition(vector<int>& nums) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    if(total % 2) return false;
    int numCount = nums.size();
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for(int i = 1; i <= numCount; ++i) {
        for(int j = target; j >= 1; --j) {
            if(nums[i - 1] <= j)
                dp[j] = dp[j] || dp[j - nums[i - 1]];
        }
    }
    return dp[target];
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,5};
    cout << canPartition(nums) << endl;
    return 0;
}
