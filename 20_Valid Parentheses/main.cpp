//
//  main.cpp
//  20_Valid Parentheses
//
//  Created by Colin on 13/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isValid(string s) {
    stack<char> stk;
    for(const char c : s) {
        if(c == '(' || c == '[' || c == '{') {
            stk.push(c);
            continue;
        }
        char target;
        if(c == ')') target = '(';
        else if(c == ']') target = '[';
        else target = '{';
        if(!stk.empty() && stk.top() == target) {
            stk.pop();
        } else {
            return false;
        }
    }
    return stk.empty();
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
