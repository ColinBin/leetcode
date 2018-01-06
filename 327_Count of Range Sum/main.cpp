//
//  main.cpp
//  327_Count of Range Sum
//
//  Created by Colin on 05/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int total = 0;

void mergeSort(vector<long> &prefix, const int left, const int right, const int lower, const int upper) {
    if(left == right - 1) return;
    int mid = left + (right - left) / 2;
    mergeSort(prefix, left, mid, lower, upper);
    mergeSort(prefix, mid, right, lower, upper);
    int i = left, j = mid;
    vector<long> temp;
    while(i < mid || j < right) {
        if(j == right || (i < mid && prefix[i] <= prefix[j])) {
            temp.push_back(prefix[i]);
            ++i;
        } else {
            temp.push_back(prefix[j]);
            ++j;
        }
    }
    j = mid;
    int k = mid;
    for(int i = left; i < mid; ++i) {
        long lowerBound = prefix[i] + lower, upperBound = prefix[i] + upper;
        while(j < right && prefix[j] <= upperBound) ++j;
        while(k < right && prefix[k] < lowerBound) ++k;
        total += (j - k);
    }
    copy(temp.begin(), temp.end(), prefix.begin() + left);
    return;
}

int countRangeSum(vector<int>& nums, int lower, int upper) {
    int numCount = nums.size();
    if(numCount == 0) return 0;
    vector<long> prefix(numCount + 1, 0);
    prefix[0] = 0;
    for(int i = 0; i < numCount; ++i) {
        prefix[i + 1] = prefix[i] + nums[i];
    }
    mergeSort(prefix, 0, numCount + 1, lower, upper);
    return total;
}

int main(int argc, const char * argv[]) {
    vector<int> arr = {-2,5,-1};
    int lower = -2, upper = 2;
    cout << countRangeSum(arr, lower, upper) << endl;
    return 0;
}

