//
//  main.cpp
//  389_Find the Difference
//
//  Created by Colin on 24/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

char findTheDifference(string s, string t) {
    unordered_map<char, int> record;
    for(const char ch : s) {
        ++record[ch];
    }
    char found = ' ';
    for(const char ch : t) {
        --record[ch];
        if(record[ch] < 0) {
            found = record[ch];
        }
    }
    return found;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
