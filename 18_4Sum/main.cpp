//
//  main.cpp
//  18_4Sum
//
//  Created by Colin on 10/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int numCount = nums.size();
    if(numCount < 4)
        return res;
    sort(nums.begin(), nums.end());
    int firstIndex = 0;
    while(firstIndex <= numCount - 4) {
        // do 3Sum
        int secondIndex = firstIndex + 1;
        while(secondIndex <= numCount - 3) {
            // do 2Sum
            // so far we have to include both nums[firstIndex] && nums[secondIndex] in the result (if possible)
            int left = secondIndex + 1, right = numCount - 1;
            while(left < right) {
                int currentSum = nums[firstIndex] + nums[secondIndex] + nums[left] + nums[right];
                // since the first two are fixed, only move the third and the fourth
                if(currentSum > target) {
                    --right;
                } else if(currentSum < target) {
                    ++left;
                } else {
                    vector<int> candidate;
                    candidate.push_back(nums[firstIndex]);
                    candidate.push_back(nums[secondIndex]);
                    candidate.push_back(nums[left]);
                    candidate.push_back(nums[right]);
                    res.push_back(candidate);
                    while(++left < right && nums[left] == nums[left - 1])
                        ;
                    while(left < --right && nums[right] == nums[right + 1])
                        ;
                }
            }
            // find the next different number to must include as the second
            while(++secondIndex <= numCount - 3 && nums[secondIndex] == nums[secondIndex - 1])
                ;
        }
        
        // find the next different number to must include
        while(++firstIndex <= numCount - 4 && nums[firstIndex] == nums[firstIndex - 1])
            ;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    auto res = fourSum(nums, 0);
    for(auto row : res) {
        for(auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
