//
//  main.cpp
//  154_Find Minimum in Rotated Sorted Array II
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
        if(nums[start] < nums[end])
            return nums[start];
        int mid = start + (end - start) / 2;
        if(nums[start] == nums[end] && nums[start] == nums[mid]) {
            --end;
            continue;
        }
        if(nums[start] <= nums[mid])
            start = mid + 1;
        else
            end = mid;
    }
    return nums[start];
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {5,5,5,5,5,5,5,5,5,1,4,4,5};
    cout << findMin(nums) << endl;
    return 0;
}
