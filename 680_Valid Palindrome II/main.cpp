//
//  main.cpp
//  680_Valid Palindrome II
//
//  Created by Colin on 26/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isPalindrome(const string &s, int left, int right) {
    while(left < right) {
        if(s[left] != s[right])
            return false;
        ++left;
        --right;
    }
    return true;
}

bool validPalindrome(string s) {
    int sLen = s.length();
    if(sLen <= 2)
        return true;
    int left = 0, right = sLen - 1;
    while(left < right) {
        if(s[left] != s[right]) {
            return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
        }
        ++left;
        --right;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
