//
//  main.cpp
//  238_Product of Array Except Self
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int numsCount = nums.size();
    vector<int> res(numsCount, 0);
    res[0] = nums[0];
    for(int i = 1; i < numsCount; ++i) {
        res[i] = res[i - 1] * nums[i];
    }
    int right = 1;
    for(int i = numsCount - 1; i > 0; --i) {
        res[i] = right * res[i - 1];
        right *= nums[i];
    }
    res[0] = right;
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,4};
    auto res = productExceptSelf(nums);
    for(auto ele : res)
        cout << ele << " ";
    cout << endl;
    return 0;
}
