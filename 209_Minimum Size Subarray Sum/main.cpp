//
//  main.cpp
//  209_Minimum Size Subarray Sum
//
//  Created by Colin on 17/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minSubArrayLen(int s, vector<int>& nums) {
    int numCount = nums.size();
    if(numCount == 0)
        return 0;
    int minLen = INT_MAX;
    int left = 0, right = 0;
    int currentSum = nums[0];
    while(right < numCount) {
        if(currentSum >= s) {
            while(left <= right && currentSum >= s) {
                currentSum -= nums[left];
                ++left;
            }
            minLen = min(minLen, right - left + 2);
        } else {
            ++right;
            if(right < numCount)
                currentSum += nums[right];
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}



int main(int argc, const char * argv[]) {
    
    return 0;
}
