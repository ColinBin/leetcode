//
//  main.cpp
//  41_First_Missing_Positive
//
//  Created by Colin on 12/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int numsCount = nums.size();
    if(numsCount == 0) {
        return 1;
    }
    for(int i = 0; i < numsCount; ++i) {
        while(nums[i] > 0 && nums[i] < numsCount && nums[nums[i] - 1] != nums[i]) {
            int a = nums[i];
            int b = nums[nums[i] - 1];
            nums[i] = b;
            nums[a - 1] = a;
        }
    }
    for(int i = 0; i < numsCount; ++i) {
        if(nums[i] != i + 1) {
            return i + 1;
        }
    }
    return numsCount + 1;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,2};
    cout << firstMissingPositive(nums) << endl;
    return 0;
}
