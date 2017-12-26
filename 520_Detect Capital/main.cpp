//
//  main.cpp
//  520_Detect Capital
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isCapital(const char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool detectCapitalUse(string word) {
    int wordLen = word.length();
    if(wordLen < 2)
        return true;
    bool isAllCapital = isCapital(word[wordLen - 1]);
    int start = isAllCapital ? 0 : 1;
    for(int i = start; i < wordLen - 1; ++i) {
        if(isCapital(word[i]) != isAllCapital)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout << detectCapitalUse("f") << endl;
    return 0;
}
