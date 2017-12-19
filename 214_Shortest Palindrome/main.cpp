//
//  main.cpp
//  214_Shortest Palindrome
//
//  Created by Colin on 18/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int expandCenter(const string &s, int left, int right) {
    
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
        --left;
        ++right;
    }
    if(left == -1) {
        return right - left - 1;
    }
    return 0;
}

string shortestPalindrome(string s) {
    int sLen = s.length();
    int maxLen = INT_MIN;
    int mid = sLen / 2;
    for(int i = 0; i <= mid; ++i) {
        int len1 = expandCenter(s, i, i + 1);
        int len2 = expandCenter(s, i, i);
        maxLen = max(maxLen, max(len1, len2));
    }
    int iter = sLen - 1;
    string leftStr = "";
    while(iter != maxLen - 1) {
        leftStr += s[iter];
        --iter;
    }
    return leftStr + s;
}

int main(int argc, const char * argv[]) {
    cout << shortestPalindrome("abacdca") << endl;
    return 0;
}
