//
//  main.cpp
//  451_Sort Characters By Frequency
//
//  Created by Colin on 26/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

string frequencySort(string s) {
    vector<string> bucket(s.length() + 1, "");
    unordered_map<char, int> record;
    for(const char ch : s) {
        ++record[ch];
    }
    for(const auto &ele : record) {
        bucket[ele.second] += ele.first;
    }
    string result = "";
    for(int i = s.length(); i >= 1; --i) {
        if(bucket[i] != "") {
            for(const char ch : bucket[i]) {
                result += string(i, ch);
            }
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
