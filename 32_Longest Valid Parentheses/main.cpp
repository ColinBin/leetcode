//
//  main.cpp
//  32_Longest Valid Parentheses
//
//  Created by Colin on 13/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int longestValidParentheses(string s) {
    int openCount = 0, closeCount = 0;
    int maxLen = 0;
    int index = 0;
    int sLen = s.length();
    while(index != sLen) {
        if(s[index++] == '(')
            ++openCount;
        else
            ++closeCount;
        if(openCount == closeCount) {
            maxLen = max(maxLen, openCount * 2);
        } else if(openCount < closeCount) {
            openCount = closeCount = 0;
        }
    }
    index = sLen - 1;
    openCount = closeCount = 0;
    while(index >= 0) {
        if(s[index--] == ')')
            ++closeCount;
        else
            ++openCount;
        if(openCount == closeCount) {
            maxLen = max(maxLen, openCount * 2);
        } else if(openCount > closeCount){
            openCount = closeCount = 0;
        }
    }
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
