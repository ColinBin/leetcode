//
//  main.cpp
//  318_Maximum Product of Word Lengths
//
//  Created by Colin on 04/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxProduct(vector<string>& words) {
    int wordCount = words.size();
    int res = 0;
    vector<int> characteristics(wordCount, 0);
    for(int i = 0; i < wordCount; ++i) {
        for(const char c : words[i]) {
            characteristics[i] |= (1 << (c - 'a'));
        }
    }
    for(int i = 0; i < wordCount - 1; ++i) {
        for(int j = i + 1; j < wordCount; ++j) {
            if((characteristics[i] & characteristics[j]) == 0) {
                res = max(res, int(words[i].length() * words[j].length()));
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
