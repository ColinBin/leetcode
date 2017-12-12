//
//  main.cpp
//  1_Two Sum
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> record;
    for(int i = 0; i < nums.size(); ++i) {
        if(record.find(target - nums[i]) != record.end()) {
            res.push_back(record[target - nums[i]]);
            res.push_back(i);
        } else {
            record[nums[i]] = i;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {2, 7, 11, 15};
    auto res = twoSum(nums, 9);
    for(auto ele : res) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
