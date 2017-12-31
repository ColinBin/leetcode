//
//  main.cpp
//  299_Bulls and Cows
//
//  Created by Colin on 30/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

string getHint(string secret, string guess) {
    int strLen = secret.length();
    int bullCount = 0, cowCount = 0;
    vector<int> record1(10, 0), record2(10, 0);
    for(int i = 0; i < strLen; ++i) {
        if(secret[i] == guess[i])
            ++bullCount;
        else {
            ++record1[secret[i] - '0'];
            ++record2[guess[i] - '0'];
        }
    }
    for(int i = 0; i < 10; ++i) {
        cowCount += min(record1[i], record2[i]);
    }
    return to_string(bullCount) + "A" + to_string(cowCount) + "B";
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
