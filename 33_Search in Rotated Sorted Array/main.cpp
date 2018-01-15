//
//  main.cpp
//  33_Search in Rotated Sorted Array
//
//  Created by Colin on 14/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int binarySearch(const vector<int> &nums, const int target, int left, int right) {
    if(target < nums[left] || target > nums[right]) return -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int numCount = nums.size();
    int left = 0, right = numCount - 1;
    if(numCount == 0) return -1;
    while(left <= right) {
        if(nums[left] <= nums[right])
            return binarySearch(nums, target, left, right);
        int mid = left + (right - left) / 2;
        if(nums[mid] >= nums[left]) {
            if(target >= nums[left] && target <= nums[mid]) {
                return binarySearch(nums, target, left, mid);
            } else {
                left = mid + 1;
            }
        } else {
            if(target >= nums[mid] && target <= nums[right]) {
                return binarySearch(nums, target, mid, right);
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
