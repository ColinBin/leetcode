//
//  main.cpp
//  39_combination_sum
//
//  Created by Colin on 11/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &res, const vector<int> &candidates, vector<int> &tempList, int remain, int index) {
    for(int i = index; i < candidates.size(); ++i) {
        if(candidates[i] < remain) {
            tempList.push_back(candidates[i]);
            dfs(res, candidates, tempList, remain - candidates[i], i);
            tempList.pop_back();
        } else if(candidates[i] > remain){
            return;
        } else {
            tempList.push_back(candidates[i]);
            res.push_back(tempList);
            tempList.pop_back();
            return;
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    if(candidates.size() == 0) {
        return res;
    }
    sort(candidates.begin(), candidates.end());
    vector<int> tempList;
    dfs(res, candidates, tempList, target, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    auto res = combinationSum(candidates, target);
    return 0;
}
