//
//  main.cpp
//  315_Count of Smaller Numbers After Self
//
//  Created by Colin on 05/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void mergeSort(vector<pair<int, int>> &nums, vector<int> &res, int left, int right) {
    if(left >= right - 1) return;   // only one element
    int mid = left + (right - left) / 2;
    mergeSort(nums, res, left, mid);
    mergeSort(nums, res, mid, right);
    vector<pair<int, int>> temp;
    int i = left, j = mid;
    int rightCount = 0;
    while(i < mid || j < right) {
        if(j == right || (i < mid && nums[i].first <= nums[j].first)) {
            temp.push_back(nums[i]);
            res[nums[i].second] += rightCount;
            ++i;
        } else {
            temp.push_back(nums[j]);
            ++rightCount;
            ++j;
        }
    }
    copy(temp.begin(), temp.begin(), nums.begin() + left);
    return;
}

vector<int> countSmaller(vector<int>& nums) {
    int numCount = nums.size();
    vector<pair<int, int>> arr;
    vector<int> res(numCount, 0);
    for(int i = 0; i < numCount; ++i) {
        arr.push_back({nums[i], i});
    }
    mergeSort(arr, res, 0, numCount);
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
