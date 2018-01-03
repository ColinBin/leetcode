//
//  main.cpp
//  639_Decode Ways II
//
//  Created by Colin on 02/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int numDecodings(string s) {
    int sLen = s.length();
    if(sLen == 0) return 0;
    int mod = 1000000007;
    long endWithAny = 1, endWithOne = 0, endWithTwo = 0;
    for(const char c : s) {
        long newAny = 0, newOne = 0, newTwo = 0;
        if(c == '*') {
            newAny = endWithAny * 9 + endWithOne * 9 + endWithTwo * 6;
            newOne = endWithAny;
            newTwo = endWithAny;
        } else {
            if(c == '0') {
                newAny = endWithOne + endWithTwo;
            } else if(c >= '1' && c <= '6') {
                newAny = endWithAny + endWithOne + endWithTwo;
            } else {
                newAny = endWithAny + endWithOne;
            }
            newOne = (c == '1') * endWithAny;
            newTwo = (c == '2') * endWithAny;
        }
        endWithAny = newAny % mod;
        endWithOne = newOne;
        endWithTwo = newTwo;
    }
    return endWithAny;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
