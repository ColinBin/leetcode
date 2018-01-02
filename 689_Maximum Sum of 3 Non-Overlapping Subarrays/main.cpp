//
//  main.cpp
//  689_Maximum Sum of 3 Non-Overlapping Subarrays
//
//  Created by Colin on 31/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    queue<int> q;
    int numCount = nums.size();
    vector<int> data;
    int currentSum = 0;
    // subsum array of size k
    for(int i = 0; i < numCount; ++i) {
        q.push(nums[i]);
        currentSum += nums[i];
        if(q.size() >= k) {
            if(q.size() > k) {
                int value = q.front();
                q.pop();
                currentSum -= value;
            }
            data.push_back(currentSum);
        }
    }
    // dp solution
    vector<vector<int>> dp(data.size() + k, vector<int> (3 + 1, 0));
    for(int i = data.size() - 1; i >= 0; --i) {
        for(int j = 1; j <= 3; ++j) {
            dp[i][j] = max(dp[i + k][j - 1] + data[i], dp[i + 1][j]);
        }
    }
    vector<int> res;
    int i = 0, j = 3;
    while(j != 0) {
        if(dp[i + k][j - 1] + data[i] >= dp[i + 1][j]) {
            res.push_back(i);
            i = i + k;
            j = j - 1;
        } else {
            i = i + 1;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,1,2,6,7,5,1};
    auto res = maxSumOfThreeSubarrays(nums, 2);
    for(const int ele : res) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
