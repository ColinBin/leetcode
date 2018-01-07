//
//  main.cpp
//  493_Reverse Pairs
//
//  Created by Colin on 06/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int total = 0;

void mergeAndFind(vector<int> &nums, int left, int right) {
    if(left >= right - 1) return;
    const int mid = left + (right - left) / 2;
    mergeAndFind(nums, left, mid);
    mergeAndFind(nums, mid, right);
    int i = left, j = mid;
    for(int i = left; i < mid; ++i) {
        while(j < right && long(nums[j]) * 2 < nums[i]) ++j;
        total += j - mid;
    }
    inplace_merge(nums.begin() + left, nums.begin() + mid, nums.begin() + right);
    return;
}

int reversePairs(vector<int>& nums) {
    int numCount = nums.size();
    if(numCount < 2) return 0;
    mergeAndFind(nums, 0, numCount);

    return total;
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {1,3,2,3,1};
    cout << reversePairs(arr) << endl;
    return 0;
}
