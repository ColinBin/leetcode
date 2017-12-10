//
//  main.cpp
//  540_Single Element in a Sorted Array
//
//  Created by Colin on 09/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int>& nums) {
    int numCount = nums.size();
    int start = 0, end = numCount - 1;
    while(start != end) {
        int mid = start + (end - start) / 2;
        bool isOdd = (mid - start) % 2;
        if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
            return nums[mid];
        }
        if(isOdd) {
            if(nums[mid] == nums[mid + 1])
                end = mid - 1;
            else
                start = mid + 1;
        } else {
            if(nums[mid] != nums[mid + 1])
                end = mid;
            else
                start = mid;
        }
    }
    return nums[start];
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums) << endl;
    return 0;
}
