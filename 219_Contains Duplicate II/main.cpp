//
//  main.cpp
//  219_Contains Duplicate II
//
//  Created by Colin on 04/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int numCount = nums.size();
    if(k < 0 || numCount < 2)
        return false;
    map<int, int> records;
    for(int i = 0; i < numCount; ++i) {
        int num = nums[i];
        if(records.find(num) != records.end() && i - records[num] <= k) {
            return true;
        } else {
            records[num] = i;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,4,3,1,4,1};
    cout << containsNearbyDuplicate(nums, 1) << endl;
    return 0;
}
