//
//  main.cpp
//  336_Palindrome Pairs
//
//  Created by Colin on 22/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isPalindrome(const string &str) {
    int left = 0, right = str.length() - 1;
    while(left < right) {
        if(str[left] != str[right]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> res;
    unordered_map<string, int> record;
    int wordCount = words.size();
    if(wordCount < 2)
        return res;
    for(int i = 0; i < wordCount; ++i) {
        record[words[i]] = i;
    }
    for(int i = 0; i < wordCount; ++i) {
        const string &word = words[i];
        int wordLen = word.length();
        for(int j = 0; j <= wordLen; ++j) {
            string leftPart = word.substr(0, j), rightPart = word.substr(j);
            if(isPalindrome(leftPart)) {
                string target = string(rightPart.rbegin(), rightPart.rend());
                if(record.find(target) != record.end() && record[target] != i) {
                    vector<int> current;
                    current.push_back(record[target]);
                    current.push_back(i);
                    res.push_back(current);
                }
            }
            if(isPalindrome(rightPart)) {
                string target = string(leftPart.rbegin(), leftPart.rend());
                if(record.find(target) != record.end() && record[target] != i && target.length() != 0) {
                    vector<int> current;
                    current.push_back(i);
                    current.push_back(record[target]);
                    res.push_back(current);
                }
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
