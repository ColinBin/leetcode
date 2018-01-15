//
//  main.cpp
//  81_Search in Rotated Sorted Array II
//
//  Created by Colin on 14/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool binarySearch(const vector<int> &nums, const int target, int left, int right) {
    if(target < nums[left] || target > nums[right]) return false;
    if(nums[left] == nums[right]) return target == nums[left];
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target)
            return true;
        else if(nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

bool search(vector<int>& nums, int target) {
    int numCount = nums.size();
    if(numCount == 0) return false;
    int left = 0, right = numCount - 1;
    while(left <= right) {
        if(nums[left] < nums[right])
            return binarySearch(nums, target, left, right);
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) return true;
        if(nums[left] == nums[right] && nums[left] == nums[mid]) {
            ++left;
            --right;
            continue;
        }
        if(nums[mid] >= nums[left]) {
            if(target >= nums[left] && target <= nums[mid])
                return binarySearch(nums, target, left, mid);
            else {
                left = mid + 1;
            }
        } else {
            if(target >= nums[mid] && target <= nums[right])
                return binarySearch(nums, target, mid, right);
            else
                right = mid - 1;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
