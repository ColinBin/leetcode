//
//  main.cpp
//  40_combination_sum_two
//
//  Created by Colin on 11/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using std::set; using std::cout; using std::endl;
using std::vector;

void dfs(vector<vector<int>> &res, vector<int> &candidates, vector<int> &tempList, int remain, int index) {
    int previous = -1;
    for(int i = index; i < candidates.size(); ++i) {
        if(candidates[i] != previous) {
            previous = candidates[i];
            if(candidates[i] < remain) {
                tempList.push_back(candidates[i]);
                dfs(res, candidates, tempList, remain - candidates[i], i + 1);
                tempList.pop_back();
            } else if(candidates[i] == remain) {
                tempList.push_back(candidates[i]);
                res.push_back(tempList);
                tempList.pop_back();
                break;
            } else {
                break;
            }
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
    vector<int> candidates = {10};
    int target = 8;
    auto res = combinationSum2(candidates, target);
    for(auto v : res) {
        for(auto ele : v) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
