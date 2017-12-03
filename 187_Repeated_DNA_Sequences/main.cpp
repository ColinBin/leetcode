//
//  main.cpp
//  187_Repeated_DNA_Sequences
//
//  Created by Colin on 02/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

vector<string> findRepeatedDnaSequences(string s) {
    vector<string> res;
    int sLen = s.length();
    unordered_map<string, int> records;
    for(int i = 0; i <= sLen - 10; ++i) {
        string current = s.substr(i, 10);
        ++records[current];
    }
    for(auto record : records) {
        if(record.second > 1)
            res.push_back(record.first);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto result = findRepeatedDnaSequences(s);
    for(auto ele : result)
        cout << ele << " ";
    cout << endl;
    return 0;
}
