//
//  main.cpp
//  205_Isomorphic Strings
//
//  Created by Colin on 18/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool isIsomorphic(string s, string t) {
    unordered_map<char, char> mapped;
    unordered_set<char> used;
    int len = s.length();
    for(int i = 0; i < len ; ++i) {
        if(mapped.find(s[i]) != mapped.end()) {
            if(mapped[s[i]] != t[i])
                return false;
        } else {
            if(used.find(t[i]) != used.end())
                return false;
            used.insert(t[i]);
            mapped[s[i]] = t[i];
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout << isIsomorphic("egga", "adda") << endl;
    return 0;
}
