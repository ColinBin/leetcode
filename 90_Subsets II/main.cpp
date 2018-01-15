//
//  main.cpp
//  90_Subsets II
//
//  Created by Colin on 11/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void helper(vector<vector<int>> &res, const vector<int> &nums, vector<int> &temp, int index) {
    if(index == nums.size()) {
        res.push_back(temp);
        return;
    }
    int next = index + 1;
    while(next != nums.size() && nums[next] == nums[next - 1]) ++next;
    int count = next - index;
    
    helper(res, nums, temp, next);
    
    for(int i = 0; i < count; ++i) {
        temp.push_back(nums[index]);
        helper(res, nums, temp, next);
    }
    for(int i = 0; i < count; ++i) {
        temp.pop_back();
    }
    return;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<int> temp;
    helper(res, nums, temp, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
