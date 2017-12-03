//
//  main.cpp
//  153_Find Minimum in Rotated Sorted Array
//
//  Created by Colin on 03/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    int numCount = nums.size();
    int start = 0, end = numCount - 1;
    while(start < end) {
        if(nums[start] <= nums[end])
            return nums[start];
        int mid = start + (end - start) / 2;
        if(nums[mid] >= nums[start])
            start = mid + 1;
        else
            end = mid;
    }
    return nums[start];
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums) << endl;
    return 0;
}
