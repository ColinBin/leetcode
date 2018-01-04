//
//  main.cpp
//  360_Sort Transformed Array
//
//  Created by Colin on 03/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int calculate(int x, int a, int b, int c) {
    return a * x * x + b * x + c;
}

vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    int numCount = 0;
    if(a == 0) {
        if(b == 0)
            return vector<int> (numCount, c);
        else {
            for(int &num : nums) {
                num = num * b + c;
            }
            if(b < 0) reverse(nums.begin(), nums.end());
            return nums;
        }
    }
    vector<int> res;
    bool findLarger = a < 0;
    int left = 0, right = numCount - 1;
    while(left <= right) {
        int leftVal = calculate(nums[left], a, b, c), rightVal = calculate(nums[right], a, b, c);
        while(left <= right && (findLarger && leftVal >= rightVal || !findLarger && leftVal <= rightVal)) {
            res.push_back(leftVal);
            ++left;
            leftVal = calculate(nums[left], a, b, c);
        }
        while(left <= right && (findLarger && rightVal > leftVal || !findLarger && leftVal > rightVal)) {
            res.push_back(rightVal);
            --right;
            rightVal = calculate(nums[right], a, b, c);
        }
    }
    if(findLarger) reverse(res.begin(), res.end());
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
