//
//  main.cpp
//  283_Move Zeroes
//
//  Created by Colin on 10/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
    int numsCount = nums.size();
    int nextPos = 0, dummy = 0;
    while(dummy < numsCount) {
        while(dummy < numsCount && nums[dummy] == 0)
            ++dummy;
        if(dummy < numsCount) {
            swap(nums[nextPos], nums[dummy]);
            ++nextPos;
            ++dummy;
        }
    }
    return;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for(auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
