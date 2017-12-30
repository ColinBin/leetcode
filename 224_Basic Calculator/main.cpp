//
//  main.cpp
//  224_Basic Calculator
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int calculate(string s) {
    int sign = 1;
    stack<int> stk;
    stk.push(sign);
    int number = 0;
    int result = 0;
    s += '+';
    for(const char c : s) {
        if(c >= '0' && c <= '9') {
            number = number * 10 + (c - '0');
        } else if(c == '+' || c == '-'){
            result += sign * number;
            number = 0;
            sign = stk.top() * (c == '+' ? 1 : -1);
        } else if(c == '(') {
            stk.push(sign);
        } else if(c == ')') {
            stk.pop();
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
