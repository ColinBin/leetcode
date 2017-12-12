//
//  main.cpp
//  161_One Edit Distance
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

bool isOneEditDistance(string s, string t) {
    int sLen = s.length(), tLen = t.length();
    if(abs(sLen - tLen) > 1)
        return false;
    if(sLen == 0 || tLen == 0) {
        if(sLen == 1 || tLen == 1)
            return true;
        return false;
    }
    int minLen = min(sLen, tLen);
    for(int i = 0; i < minLen; ++i) {
        if(s[i] != t[i]) {
            return s.substr(i + 1) == t.substr(i + 1) || s.substr(i) == t.substr(i + 1) || s.substr(i + 1) == t.substr(i);
        }
    }
    return abs(sLen - tLen) == 1;
}

int main(int argc, const char * argv[]) {
    string s = "abcdefg", t = "abcdeg";
    cout << isOneEditDistance(s, t) << endl;
    return 0;
}
