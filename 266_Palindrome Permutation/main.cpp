//
//  main.cpp
//  266_Palindrome Permutation
//
//  Created by Colin on 15/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool canPermutePalindrome(string s) {
    unordered_map<char, int> record;
    for(const char ch : s) {
        ++record[ch];
    }
    int oddCount = 0;
    for(const auto &ele : record) {
        if(ele.second & 0x01) {
            ++oddCount;
            if(oddCount == 2) {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
