//
//  main.cpp
//  340_Longest Substring with At Most K Distinct Characters
//
//  Created by Colin on 20/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstringKDistinct(string s, int k) {
    int sLen = s.length();
    unordered_map<char, int> record;
    int left = 0, right = 0;
    while(right < sLen) {
        ++record[s[right]];
        if(record.size() > k) {
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
