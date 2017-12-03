//
//  main.cpp
//  22_generate_parentheses
//
//  Created by Colin on 11/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<string> &res, int leftCount, int rightCount, const int total, const string & temp) {
    if(rightCount == total) {
        res.push_back(temp);
        return;
    }
    if(leftCount < total) {
        dfs(res, leftCount + 1, rightCount, total, temp + "(");
    }
    if(rightCount < leftCount) {
        dfs(res, leftCount, rightCount + 1, total, temp + ")");
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    if(n == 0) {
        return res;
    }
    dfs(res, 0, 0, n, "");
    return res;
}

int main(int argc, const char * argv[]) {
    int n = 3;
    auto res = generateParenthesis(n);
    for(auto str : res) {
        cout << str << endl;
    }
    return 0;
}
