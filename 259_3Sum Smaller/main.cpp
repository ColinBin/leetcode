//
//  main.cpp
//  259_3Sum Smaller
//
//  Created by Colin on 15/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int threeSumSmaller(vector<int>& nums, int target) {
    int numCount = nums.size();
    if(numCount < 3)
        return 0;
    sort(nums.begin(), nums.end());
    int count = 0;
    for(int i = 0; i <= numCount - 3; ++i) {
        int left = i + 1, right = numCount - 1;
        while(left < right) {
            int currentSum = nums[i] + nums[left] + nums[right];
            if(currentSum < target) {
                count += (right - left);
                ++left;
            } else {
                --right;
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
