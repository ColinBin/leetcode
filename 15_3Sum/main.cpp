//
//  main.cpp
//  15_3Sum
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int numCount = nums.size();
    if(numCount < 3)
        return res;
    sort(nums.begin(), nums.end());
    int currentIndex = 0;
    while(currentIndex <= numCount - 3) {
        // for each chosen first element, find -value in remaining sorted array
        int left = currentIndex + 1, right = numCount - 1;
        while(left < right) {
            int currentSum = nums[left] + nums[right] + nums[currentIndex];
            if(currentSum < 0) {
                ++left;
            } else if(currentSum > 0) {
                --right;
            } else {
                vector<int> validCombination;
                validCombination.push_back(nums[currentIndex]);
                validCombination.push_back(nums[left]);
                validCombination.push_back(nums[right]);
                res.push_back(validCombination);
                while(++left < right && nums[left] == nums[left - 1])
                    ;
                while(left < --right && nums[right] == nums[right + 1])
                    ;
            }
        }
        while(++currentIndex <= numCount - 3 && nums[currentIndex] == nums[currentIndex - 1])
            ;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = threeSum(nums);
    for(auto row : res) {
        for(auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
