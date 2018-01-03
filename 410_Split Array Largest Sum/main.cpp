//
//  main.cpp
//  410_Split Array Largest Sum
//
//  Created by Colin on 01/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isValid(const vector<int> &nums, const int m, const int currentMax) {
    int setCount = 0;
    int currentSum = 0;
    for(const int num : nums) {
        if(currentSum + num > currentMax) {
            ++setCount;
            currentSum = num;
            if(setCount == m)
                return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}

int splitArray(vector<int>& nums, int m) {
    int maxEle = INT_MIN;
    int sumEle = 0;
    for(const int num : nums) {
        maxEle = max(maxEle, num);
        sumEle += num;
    }
    int left = maxEle, right = sumEle;
    while(left < right) {
        int mid = left + (right - left) / 2;
        if(isValid(nums, m, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
