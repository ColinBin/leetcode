//
//  main.cpp
//  34_Search for a Range
//
//  Created by Colin on 14/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    int numCount = nums.size();
    if(numCount == 0 || target < nums[0] || target > nums[numCount - 1]) return res;
    int start = 0, finish = 0;
    int left = 0, right = numCount - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            right = mid;
        else if(nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if(nums[left] != target) return res;
    start = left;
    right = numCount - 1;
    while(left < right) {
        int mid = left + (right - left + 1) / 2;
        if(nums[mid] == target) {
            left = mid;
        } else {
            right = mid - 1;
        }
    }
    finish = left;
    res[0] = start;
    res[1] = finish;
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
