//
//  main.cpp
//  316_Remove Duplicate Letters
//
//  Created by Colin on 10/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string removeDuplicateLettersStack(string s) {
    vector<int> charCount(256, 0);
    vector<bool> charVisited(256, false);
    for(const char ch : s)
        ++charCount[ch];
    string res = "";
    for(const char ch : s) {
        --charCount[ch];
        if(charVisited[ch])
            continue;
        while(res.length() != 0 && res.back() > ch && charCount[res.back()] > 0) {
            charVisited[res.back()] = false;
            res.pop_back();
        }
        res += ch;
        charVisited[ch] = true;
    }
    return res;
}

string removeDuplicateLetters(string s) {
    return removeDuplicateLettersStack(s);
    int sLen = s.length();
    if(sLen < 2)
        return s;
    vector<int> charCount(26, 0);
    for(const char ch : s)
        ++charCount[ch - 'a'];
    int currentPos = 0;
    for(int i = 0; i < sLen; ++i) {
        --charCount[s[i] - 'a'];
        if(s[i] < s[currentPos])
            currentPos = i;
        if(charCount[s[i] - 'a'] == 0)
            break;
    }
    string next = s.substr(currentPos + 1);
    next.erase(remove(next.begin(), next.end(), s[currentPos]), next.end());
    return s[currentPos] + removeDuplicateLetters(next);
}


int main(int argc, const char * argv[]) {
    string s = "cbacdcbc";
    string res = removeDuplicateLetters(s);
    cout << res << endl;
    return 0;
}
