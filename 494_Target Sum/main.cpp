//
//  main.cpp
//  494_Target Sum
//
//  Created by Colin on 31/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int getKey(int i, int t) {
    return (i << 10) + t;
}

int helper(unordered_map<int, int> &record, const vector<int> &nums, int i, int target) {
    if(i == 0) return 0;
    int currentKey = getKey(i, target);
    if(record.find(currentKey) != record.end())
        return record[currentKey];
    record[currentKey] = helper(record, nums, i - 1, target - nums[i - 1]) + helper(record, nums, i - 1, target + nums[i - 1]);
    return record[currentKey];
}

int findTargetSumWays(vector<int>& nums, int S) {
    unordered_map<int, int> record;
    int numCount = nums.size();
    if(numCount == 0) return 0;
    if(nums[0] == 0) record[getKey(1, 0)] = 2;
    else {
        record[getKey(1, nums[0])] = 1;
        record[getKey(1, -nums[0])] = 1;
    }
    return helper(record, nums, numCount, S);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
