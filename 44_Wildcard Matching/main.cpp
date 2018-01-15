//
//  main.cpp
//  44_Wildcard Matching
//
//  Created by Colin on 14/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isMatch(string p, string s) {
    int sLen = s.length(), pLen = p.length();
    vector<bool> dp(pLen + 1, false);
    dp[0] = true;
    for(int i = 1; i <= sLen; ++i) {
        bool lastPrev = dp[0];
        char sChar = s[i - 1];
        dp[0] = lastPrev && (sChar == '*');
        for(int j = 1; j <= pLen; ++j) {
            int newLastPrev = dp[j];
            if(sChar == '*') {
                dp[j] = dp[j] || dp[j - 1];
            } else if(sChar == '?' || sChar == p[j - 1]){
                dp[j] = lastPrev;
            } else {
                dp[j] = false;
            }
            lastPrev = newLastPrev;
        }
    }
    return dp[pLen];
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
