//
//  main.cpp
//  201_Bitwise AND of Numbers Range
//
//  Created by Colin on 12/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
    if(m == n)
        return m;
    unsigned int mask = 1 << 31;
    int res = 0;
    for(int i = 0; i < 32; ++i) {
        unsigned int newMask = mask >> i;
        if((m & newMask) == (n & newMask)) {
            res |= ((m & newMask) > 0);
            res <<= 1;
        } else {
            res <<= 32 - i;
            break;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout << rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
