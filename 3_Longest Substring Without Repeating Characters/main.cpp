//
//  main.cpp
//  3_Longest Substring Without Repeating Characters
//
//  Created by Colin on 08/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> record;
    int sLen = s.length();
    if(sLen == 0) return 0;
    int left = 0, right = 1;
    ++record[s[0]];
    int duplicateCount = 0;
    while(right != sLen) {
        char current = s[right];
        if(duplicateCount == 0 && record[current] == 0) {
            ++right;
            ++record[current];
        } else {
            char toRemove = s[left];
            if(record[toRemove] >= 2) --duplicateCount;
            --record[toRemove];
            if(record[current] >= 1) ++duplicateCount;
            ++record[current];
            ++left;
            ++right;
        }
    }
    return right - left;
}

int main(int argc, const char * argv[]) {
    cout << lengthOfLongestSubstring("aab") << endl;
    return 0;
}
