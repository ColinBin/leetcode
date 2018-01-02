//
//  main.cpp
//  525_Contiguous Array
//
//  Created by Colin on 01/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int findMaxLength(vector<int>& nums) {
    int numCount = nums.size();
    int currentSum = 0;
    unordered_map<int, int> record;
    record[0] = 0;
    int maxLen = 0;
    for(int i = 0; i < numCount; ++i) {
        currentSum += (nums[i] == 0 ? -1 : 1);
        if(record.find(currentSum) != record.end()) {
            maxLen = max(maxLen, i + 1 - record[currentSum]);
        } else {
            record[currentSum] = i + 1;
        }
    }
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
