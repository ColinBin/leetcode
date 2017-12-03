//
//  main.cpp
//  139_word_break
//
//  Created by Colin on 17/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool dfs(const set<string> &wordDict, vector<int> &memo, const string &target, int start);
bool wordBreak(string s, vector<string>& wordDict) {
    int wordCount = wordDict.size();
    if(wordCount == 0) {
        return false;
    }
    vector<int> memo(s.length(), -1);
    // DFS
    return dfs(set<string> (wordDict.begin(), wordDict.end()), memo, s, 0);
}
bool dfs(const set<string> &wordDict, vector<int> &memo, const string &target, int start) {
    if(start == target.length()){
        return true;
    }
    if(memo[start] != -1) {
        return memo[start];
    }
    for(int end = start + 1; end <= target.length(); ++end) {
        string temp = target.substr(start, end - start);
        if(wordDict.find(temp) != wordDict.end() && dfs(wordDict, memo, target, end)) {
            memo[start] = 1;
            return true;
        }
    }
    memo[start] = 0;
    return false;
}

bool wordBreakDP(string s, vector<string>& wordDict) {
    int wordCount = wordDict.size();
    if(wordCount == 0) {
        return false;
    }
    vector<vector<bool>> dp(s.length(), vector<bool> (s.length(), false));
    set<string> dict(wordDict.begin(), wordDict.end());
    for(int len = 1; len <= s.length(); ++len) {
        for(int i = 0; i <= s.length() - len; ++i) {
            int j = len + i - 1;
            if(dict.find(s.substr(i, len)) != dict.end()) {
                dp[i][j] = true;
                continue;
            }
            for(int k = i; k <= j - 1; ++k) {
                if(dp[i][k] && dp[k + 1][j]) {
                    dp[i][j] = true;
                    break;
                }
            }
        }
    }
    return dp[0][s.length() - 1];
}

int main(int argc, const char * argv[]) {
    string target = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreakDP(target, wordDict) << endl;
    return 0;
}
