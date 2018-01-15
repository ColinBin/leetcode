//
//  main.cpp
//  22_Generate Parentheses
//
//  Created by Colin on 10/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void dfs(vector<string> &res, string temp, int open, int close, const int n) {
    if(open == n && close == n) {
        res.push_back(temp);
        return;
    }
    if(open < n) {
        dfs(res, temp + '(', open + 1, close, n);
    }
    if(close < open) {
        dfs(res, temp + ')', open, close + 1, n);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n <= 0) return res;
    string temp = "";
    dfs(res, temp, 0, 0, n);
    return res;
}
int main(int argc, const char * argv[]) {
    
    return 0;
}
