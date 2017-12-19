//
//  main.cpp
//  216_Combination Sum III
//
//  Created by Colin on 18/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
void dfs(vector<vector<int>> &res, vector<int> &tempList, int remainCount, int index, int target) {
    if(remainCount == 0) {
        if(target == 0)
            res.push_back(tempList);
        return;
    }
    // not enough number to choose
    if(10 - index < remainCount)
        return;
    tempList.push_back(index);
    dfs(res, tempList, remainCount - 1, index + 1, target - index);
    tempList.pop_back();
    dfs(res, tempList, remainCount, index + 1, target);
    return;
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> tempList;
    dfs(res, tempList, k, 1, n);
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
