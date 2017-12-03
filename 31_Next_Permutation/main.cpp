//
//  main.cpp
//  31_Next_Permutation
//
//  Created by Colin on 12/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int numsCount = nums.size();
    if(numsCount < 2) {
        return;
    }
    int i;
    for(i = numsCount - 2; i >= 0; --i) {
        if(nums[i] >= nums[i + 1]) {
            continue;
        } else {
            int index = i + 1;
            int value = nums[i + 1];
            for(int j = i + 2; j < numsCount; ++j) {
                if(nums[j] <= nums[i]) {
                    break;
                }
                if(nums[j] > nums[i] && nums[j] < value) {
                    index = j;
                    value = nums[j];
                }
            }
            swap(nums[i], nums[index]);
            reverse(nums.begin() + i + 1, nums.end());
            return;
        }
    }
    reverse(nums.begin(), nums.end());
    return;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,2,1};
    nextPermutation(nums);
    for(auto ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
