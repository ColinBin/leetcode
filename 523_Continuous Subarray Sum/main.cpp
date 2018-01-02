//
//  main.cpp
//  523_Continuous Subarray Sum
//
//  Created by Colin on 30/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> record;
    record[0] = 0;
    int numCount = nums.size();
    int currentSum = 0;
    int zeroCount = 0;
    for(int i = 0; i < numCount; ++i) {
        currentSum += nums[i];
        if(nums[i] == 0) ++zeroCount;
        else zeroCount = 0;
        if(zeroCount >= 2) return true;
        if(k == 0) continue;
        int remainder = currentSum % k;
        if(record.find(remainder) != record.end()) {
            if(i - record[remainder] >= 2)
                return true;
        } else {
            record[remainder] = i + 1;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
