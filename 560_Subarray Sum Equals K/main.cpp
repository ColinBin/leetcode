//
//  main.cpp
//  560_Subarray Sum Equals K
//
//  Created by Colin on 05/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int numCount = nums.size();
    int currentSum = 0;
    unordered_map<int, int> record;
    record[0] = 1;
    int res = 0;
    for(int i = 0; i < numCount; ++i) {
        currentSum += nums[i];
        int target = currentSum - k;
        res += record[target];
        ++record[currentSum];
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
