//
//  main.cpp
//  438_Find All Anagrams in a String
//
//  Created by Colin on 05/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<int> findAnagrams(string s, string p) {
    int sLen = s.length(), pLen = p.length();
    vector<int> res;
    if(sLen < pLen) return res;
    int matchCount = 0;
    vector<int> recordS(26, 0), recordP(26, 0);
    for(const char c : p) {
        ++recordP[c - 'a'];
    }
    for(int i = 0; i < pLen; ++i) {
        if(++recordS[s[i] - 'a'] <= recordP[s[i] - 'a'])
            ++matchCount;
    }
    if(matchCount == pLen) res.push_back(0);
    for(int i = pLen; i < sLen; ++i) {
        int toRemove = s[i - pLen] - 'a', toAdd = s[i] - 'a';
        if(recordS[toRemove] <= recordP[toRemove])
            --matchCount;
        --recordS[toRemove];
        if(recordS[toAdd] < recordP[toAdd])
            ++matchCount;
        ++recordS[toAdd];
        if(matchCount == pLen)
            res.push_back(i - pLen + 1);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    auto res = findAnagrams("op", "by");
    
    return 0;
}
