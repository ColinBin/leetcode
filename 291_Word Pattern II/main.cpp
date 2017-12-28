//
//  main.cpp
//  291_Word Pattern II
//
//  Created by Colin on 27/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool helper(const string &pattern, const string &str, const int patternIndex,
            const int strIndex, unordered_map<char, string> &record, unordered_set<string> &checked) {
    if(pattern.length() == patternIndex && str.length() == strIndex) return true;
    if(pattern.length() - patternIndex > str.length() - strIndex) return false;
    char currentPattern = pattern[patternIndex];
    // already in the record
    if(record.find(currentPattern) != record.end()) {
        const string &word = record[currentPattern];
        if(str.length() - strIndex < word.length() || word != str.substr(strIndex, word.length()))
            return false;
        return helper(pattern, str, patternIndex + 1, strIndex + word.length(), record, checked);
    }
    // not in the record
    for(int i = strIndex + 1; i <= str.length(); ++i) {
        string currentStr = str.substr(strIndex, i - strIndex);
        if(checked.find(currentStr) != checked.end())
            continue;
        record[currentPattern] = currentStr;
        checked.insert(currentStr);
        if (helper(pattern, str, patternIndex + 1, i, record, checked)) {
            return true;
        }
        record.erase(currentPattern);
        checked.erase(currentStr);
    }
    return false;
}


bool wordPatternMatch(string pattern, string str) {
    unordered_map<char, string> record;
    unordered_set<string> checked;
    return helper(pattern, str, 0, 0, record, checked);
}

int main(int argc, const char * argv[]) {
   
    return 0;
}
