//
//  main.cpp
//  320_Generalized Abbreviation
//
//  Created by Colin on 03/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void helper(vector<string> &res, string &temp, const string &word, int index) {
    if(index >= word.length()) {
        res.push_back(temp);
        return;
    }
    temp += word[index];
    helper(res, temp, word, index + 1);
    temp.pop_back();
    int currentLen = 0;
    for(int i = index; i < word.length(); ++i) {
        ++currentLen;
        string current = temp;
        current += to_string(currentLen);
        if(i != word.length() - 1)
            current += word[i + 1];
        helper(res, current, word, index + currentLen + 1);
    }
    return ;
}

vector<string> generateAbbreviations(string word) {
    vector<string> res;
    string temp = "";
    helper(res, temp, word, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
