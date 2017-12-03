//
//  main.cpp
//  516_longest_palindromic_subsequence
//
//  Created by Colin on 09/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//
// status: AC
#include <iostream>
#include <string>
#include <vector>

using std::cout;using std::endl;
using std::string; using std::vector; using std::max;

int longestPalindromeSubseq(string s) {
    int strLen = s.length();
    if(strLen < 2) {
        return strLen;
    }
    vector<vector<int>> dp(strLen, vector<int> (strLen, 0));
    for(int i = 0; i < strLen; ++i) {
        dp[i][i] = 1;
    }

    for(int length = 2; length <= strLen; ++length) {
        for(int i = 0; i <= strLen - length; ++i) {
            int j = length + i - 1;
            if(s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    return dp[0][strLen - 1];
}

int main(int argc, const char * argv[]) {
    string s = "ddbdbdd";
    cout << longestPalindromeSubseq(s) << endl;
    return 0;
}
