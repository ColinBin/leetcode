//
//  main.cpp
//  581_Shortest Unsorted Continuous Subarray
//
//  Created by Colin on 05/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    int numCount = nums.size();
    int pivot = INT_MIN;
    int right = 0, left = numCount - 1;
    for(int i = 0; i < numCount; ++i) {
        if(nums[i] < pivot) right = i;
        pivot = max(pivot, nums[i]);
    }
    pivot = INT_MAX;
    for(int j = numCount - 1; j >= 0; --j) {
        if(nums[j] > pivot) left = j;
        pivot = min(pivot, nums[j]);
    }
    if(right <= left) return 0;
    else return right - left + 1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
