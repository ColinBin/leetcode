//
//  main.cpp
//  300_Longest Increasing Subsequence
//
//  Created by Colin on 20/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void setVal(vector<int> &dp, int value) {
    int left = 0, right = dp.size() - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(dp[mid] == value)
            return;
        else if(dp[mid] > value) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if(dp.size() == 0 || dp[left] < value) {
        dp.push_back(value);
    } else {
        dp[left] = value;
    }
}

int lengthOfLIS(vector<int>& nums) {
    vector<int> dp;
    for(const int num : nums) {
        setVal(dp, num);
    }
    return dp.size();
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
