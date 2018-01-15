//
//  main.cpp
//  78_Subsets
//
//  Created by Colin on 11/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void helper(vector<vector<int>> &res, vector<int> &temp, const vector<int> &nums, int index) {
    if(index == nums.size()) {
        res.push_back(temp);
        return ;
    }
    temp.push_back(nums[index]);
    helper(res, temp, nums, index + 1);
    temp.pop_back();
    
    helper(res, temp, nums, index + 1);
    return ;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> temp;
    helper(res, temp, nums, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
