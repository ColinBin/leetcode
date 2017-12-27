//
//  main.cpp
//  301_Remove Invalid Parentheses
//
//  Created by Colin on 26/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void helper(vector<string> &result, string current, int start, int lastRemoved, pair<char, char> &p) {
    int stack = 0;
    for(int i = start; i < current.length(); ++i) {
        if(current[i] == p.first) ++stack;
        if(current[i] == p.second) --stack;
        if(stack >= 0) continue;
        for(int j = lastRemoved; j <= i; ++j) {
            if(current[j] == ')' && (j == lastRemoved || current[j - 1] != p.second)) {
                helper(result, current.substr(0, j) + current.substr(j + 1), i, j, p);
            }
        }
        return;
    }
    reverse(current.begin(), current.end());
    if(p.first == '(') {
        helper(result, current, 0, 0, make_pair(')', '('));
    } else {
        result.push_back(current);
    }
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> result;
    helper(result, s, 0, 0, {'(', ')'});
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
