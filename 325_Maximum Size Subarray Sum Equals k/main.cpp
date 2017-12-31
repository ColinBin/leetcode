//
//  main.cpp
//  325_Maximum Size Subarray Sum Equals k
//
//  Created by Colin on 30/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxSubArrayLen(vector<int>& nums, int k) {
    int numCount = nums.size();
    unordered_map<int, int> m;
    m[0] = 0;
    int currentSum = 0;
    int maxLen = 0;
    for(int i = 0; i < numCount; ++i) {
        currentSum += nums[i];
        int target = currentSum - k;
        if(m.find(target) != m.end()) {
            maxLen = max(maxLen, i + 1 - m[target]);
        }
        if(m.find(currentSum) == m.end()) {
            m[currentSum] = i + 1;
        }
    }
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
