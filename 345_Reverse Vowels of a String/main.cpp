//
//  main.cpp
//  345_Reverse Vowels of a String
//
//  Created by Colin on 05/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <set>

using namespace std;

string reverseVowels(string s) {
    int sLen = s.length();
    set<char> vowelSet = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int left = 0, right = sLen - 1;
    while(left < right) {
        while(left < right && vowelSet.find(s[left]) == vowelSet.end())
            ++left;
        while(left < right && vowelSet.find(s[right]) == vowelSet.end())
            --right;
        if(left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
    return s;
}

int main(int argc, const char * argv[]) {
    cout << reverseVowels("leetcode") << endl;
    return 0;
}
