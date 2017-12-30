//
//  main.cpp
//  227_Basic Calculator II
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int calculate(string s) {
    int result = 0;
    int number = 0;
    char op = '+';
    stack<int> stk;
    s += '+';
    for(const char c : s) {
        if(c >= '0' && c <= '9') {
            number = number * 10 + (c - '0');
            continue;
        }
        if(c != ' ') {
            if(op == '+' || op == '-') {
                stk.push(number * (op == '+' ? 1 : -1));
            } else if(op == '*'){
                int ele = stk.top();
                stk.pop();
                stk.push(ele * number);
            } else {
                int ele = stk.top();
                stk.pop();
                stk.push(ele / number);
            }
            op = c;
            number = 0;
        }
    }
    while(!stk.empty()) {
        result += stk.top();
        stk.pop();
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
