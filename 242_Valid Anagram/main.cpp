//
//  main.cpp
//  242_Valid Anagram
//
//  Created by Colin on 10/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
    vector<int> record(26, 0);
    for(auto ch : s) {
        ++record[ch - 'a'];
    }
    for(auto ch : t) {
        --record[ch - 'a'];
    }
    for(auto ele : record) {
        if(ele != 0)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout << isAnagram("anagram", "nagaram") << endl;
    return 0;
}
