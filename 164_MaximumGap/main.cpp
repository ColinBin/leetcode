//
//  main.cpp
//  164_MaximumGap
//
//  Created by Colin on 02/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maximumGap(vector<int>& nums) {
    int numsCount = nums.size();
    if(numsCount < 2)
        return 0;
    int minVal = INT_MAX, maxVal = INT_MIN;
    // find the max and min of nums
    for(auto num : nums) {
        minVal = min(num, minVal);
        maxVal = max(num, maxVal);
    }
    int gap = max(1, (maxVal - minVal) / (numsCount - 1));
    int bucketCount = (maxVal - minVal) / gap + 1;
    // mark the min and max of each bucket
    vector<int> minRecord(bucketCount, INT_MAX);
    vector<int> maxRecord(bucketCount, INT_MIN);
    for(int num : nums) {
        int index = (num - minVal) / gap;
        minRecord[index] = min(minRecord[index], num);
        maxRecord[index] = max(maxRecord[index], num);
    }
    int prev = minVal, maxGap = INT_MIN;
    for(int i = 0; i < bucketCount; ++i) {
        if(minRecord[i] == INT_MAX)
            continue;
        maxGap = max(maxGap, minRecord[i] - prev);
        prev = maxRecord[i];
    }
    return maxGap;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2,2,2,1};
    cout << maximumGap(nums) << endl;
    return 0;
}
