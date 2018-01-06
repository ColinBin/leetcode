//
//  main.cpp
//  647_Palindromic Substrings
//
//  Created by Colin on 05/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int countPalinfrome(const string &s, int left, int right) {
    int count = 0;
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
        ++count;
        --left;
        ++right;
    }
    return count;
}

int countSubstrings(string s) {
    int sLen = s.length();
    int total = 0;
    for(int i = 0; i < sLen; ++i) {
        total += countPalinfrome(s, i, i);
        total += countPalinfrome(s, i, i + 1);
    }
    return total;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
