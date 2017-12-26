//
//  main.cpp
//  290_Word Pattern
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool wordPattern(string pattern, string str) {
    istringstream is(str);
    unordered_map<string, int> s2i;
    unordered_map<char, int> c2i;
    int patternLen = pattern.length();
    int i = 0;
    for(string temp; is >> temp; ++i) {
        // str too long or do not match
        if(i == patternLen || s2i[temp] != c2i[pattern[i]])
            return false;
        s2i[temp] = c2i[pattern[i]] = i + 1;
    }
    // if pattern is not too long
    return i == patternLen;
}

int main(int argc, const char * argv[]) {
    cout << wordPattern("abba", "dog cat cat dog") << endl;
    return 0;
}
