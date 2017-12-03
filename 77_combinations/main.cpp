//
//  main.cpp
//  77_combinations
//
//  Created by Colin on 05/11/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &res, vector<int> &tempList, int currN, int currK) {
    if(currK == 0) {
        res.push_back(tempList);
        return;
    }
    // make sure currN >= currK
    if(currN == currK) {
        tempList.push_back(currN);
        // actually, must push all
        dfs(res, tempList, currN - 1, currK - 1);
        tempList.pop_back();
    } else {
        tempList.push_back(currN);
        dfs(res, tempList, currN - 1, currK - 1);
        tempList.pop_back();
        dfs(res, tempList, currN - 1, currK);
    }
}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> res;
    if(k > n) {
        return res;
    } else if(k == 0) {
        return vector<vector<int>> (1, vector<int> ());
    }
    vector<int> tempList;
    dfs(res, tempList, n, k);
    return res;
}

int main(int argc, const char * argv[]) {
    auto res = combine(4, 2);
    for(auto row: res) {
        for(auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}
