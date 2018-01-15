//
//  main.cpp
//  46_Permutations
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
    for(int i = index; i < temp.size(); ++i) {
        swap(temp[i], temp[index]);
        helper(res, temp, index + 1);
        swap(temp[i], temp[index]);
    }
    return;
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    helper(res, nums, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
