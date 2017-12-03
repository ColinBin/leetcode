//
//  main.cpp
//  10_regular_expression_matching
//
//  Created by Colin on 17/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(string s, string p) {
    // moving backwards
    int sLen = s.length(), pLen = p.length();
    if(sLen == 0 && pLen == 0) {
        return true;
    } else if(pLen == 0) {
        return false;
    }
    vector<vector<bool>> dp(sLen + 1, vector<bool> (pLen + 1, false));
    // for(int i = 0; i <= sLen; ++i) {
    //     dp[i][0] = false;
    // }
    dp[0][0] = true;
    for(int i = 1; i <= pLen; ) {
        if(p[i - 1] != '*') {
            if(i == pLen) {
                dp[0][pLen] = false;
                break;
            } else if(p[i] != '*') {
                for(int j = i; j <= pLen; ++j) {
                    dp[0][j] = false;
                }
                break;
            } else {
                dp[0][i] = false;
                dp[0][i + 1] = true;
                i += 2;
            }
        }
    }
    for(int i = 1; i <= sLen; ++i) {
        for(int j = 1; j <= pLen; ++j) {
            bool mess = false;
            if(j + 1 <= pLen && p[j] == '*') {
                mess = true;
            }
            if(!mess) {
                if(p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = false;
                }
            } else {
                ++j;
                if(p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                } else {
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }
    for(auto row: dp) {
        for(auto ele: row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return dp[sLen][pLen];
}

int main(int argc, const char * argv[]) {
    string s = "aab", p = "c*a*b";
    cout << isMatch(s, p) << endl;
    return 0;
}
