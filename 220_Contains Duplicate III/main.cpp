//
//  main.cpp
//  220_Contains Duplicate III
//
//  Created by Colin on 04/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int numCount = nums.size();
    if(numCount < 2 || k <= 0 || t < 0)
        return false;
    unordered_map<long, long> records;
    long bucketSize = long(t) + 1;
    for(int i = 0; i < numCount; ++i) {
        long mappedNum = long(nums[i]) - INT_MIN;
        int bucketIndex = mappedNum / bucketSize;
        if(records.find(bucketIndex) != records.end())
            return true;
        if(records.find(bucketIndex - 1) != records.end() && mappedNum - records[bucketIndex - 1] <= t)
            return true;
        if(records.find(bucketIndex + 1) != records.end() && records[bucketIndex + 1] - mappedNum <= t)
            return true;
        if(i >= k) {
            long oldestIndex = (long(nums[i - k]) - INT_MIN) / bucketSize;
            records.erase(oldestIndex);
        }
        records[bucketIndex] = mappedNum;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 9, 12, 4, 18, 7, -3};
    cout << containsNearbyAlmostDuplicate(nums, 3, 2) << endl;
    return 0;
}
