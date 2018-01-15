//
//  main.cpp
//  47_Permutations II
//
//  Created by Colin on 11/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void helper(vector<vector<int>> &res, vector<int> &temp, int index) {
    if(index == temp.size()) {
        res.push_back(temp);
        return;
    }
    unordered_set<int> used;
    for(int i = index; i < temp.size(); ++i) {
        if(used.find(temp[i]) == used.end()) {
            used.insert(temp[i]);
            swap(temp[i], temp[index]);
            helper(res, temp, index + 1);
            swap(temp[i], temp[index]);
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    helper(res, nums, 0);
    return res;
}

int main(int argc, const char * argv[]) {

    return 0;
}
