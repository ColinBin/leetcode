//
//  main.cpp
//  424_Longest Repeating Character Replacement
//
//  Created by Colin on 20/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int characterReplacement(string s, int k) {
    int sLen = s.length();
    vector<int> record(26, 0);
    int maxCount = 0;
    int left = 0, right = 0;
    while (right < sLen) {
        int currentChar = s[right] - 'A';
        ++record[currentChar];
        maxCount = max(maxCount,  record[currentChar]);
        // if the maxCount (the max number of same chars) plus k is not enough to fill current window, shift the window
        if(right - left + 1 > maxCount + k) {
            --record[s[left] - 'A'];
            ++left;
            ++right;
        } else {
            // window can be expanded
            ++right;
        }
    }
    return sLen - left;
}

int main(int argc, const char * argv[]) {
    cout << characterReplacement("ABAAB", 1) << endl;
    return 0;
}
