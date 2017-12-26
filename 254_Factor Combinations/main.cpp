//
//  main.cpp
//  254_Factor Combinations
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void helper(vector<vector<int>> &res, vector<int> &tempList, int start, int remain) {
    if(remain == 1) {
        if(tempList.size() > 1) {
            res.push_back(tempList);
        }
        return;
    }
    
    for(int i = start; i <= sqrt(remain); ++i) {
        if(remain % i != 0 || remain / i < i)
            continue;
        tempList.push_back(i);
        helper(res, tempList, i, remain / i);
        tempList.pop_back();
    }
    // 4 * 8, when end with 8
    tempList.push_back(remain);
    helper(res, tempList, remain, 1);
    tempList.pop_back();
    return;
}

vector<vector<int>> getFactors(int n) {
    vector<vector<int>> res;
    vector<int> tempList;
    helper(res, tempList, 2, n);
    return res;
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
