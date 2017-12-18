//
//  main.cpp
//  213_House Robber II
//
//  Created by Colin on 17/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int rob(const vector<int> &nums, int left, int right) {
    if(left == right)
        return nums[left];
    int p = nums[left], pp = 0;
    for(int i = left + 1; i <= right; ++i) {
        int current = max(pp + nums[i], p);
        pp = p;
        p = current;
    }
    return p;
}

int rob(vector<int>& nums) {
    int numCount = nums.size();
    if(numCount == 0)
        return 0;
    if(numCount == 1)
        return nums[0];
    return max(rob(nums, 0, numCount - 2), rob(nums, 1, numCount - 1));
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
