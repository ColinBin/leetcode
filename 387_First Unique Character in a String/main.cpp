//
//  main.cpp
//  387_First Unique Character in a String
//
//  Created by Colin on 26/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int firstUniqChar(string s) {
    int sLen = s.length();
    vector<int> record(26, 0);
    if(sLen == 0)
        return -1;
    for(const char ch : s){
        ++record[ch - 'a'];
    }
    for(int i = 0; i < sLen; ++i) {
        if(record[s[i]] == 1)
            return i;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
