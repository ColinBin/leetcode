//
//  main.cpp
//  159_Longest Substring with At Most Two Distinct Characters
//
//  Created by Colin on 20/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstringTwoDistinct(string s) {
    unordered_map<char, int> record;
    int sLen = s.length();
    int left = 0, right = 0;
    while(right < sLen) {
        char current = s[right];
        ++record[current];
        if(record.size() > 2) {
            if(--record[s[left]] == 0) {
                record.erase(s[left]);
            }
            ++left;
        }
        ++right;
    }
    return sLen - left;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
