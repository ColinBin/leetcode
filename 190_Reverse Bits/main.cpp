//
//  main.cpp
//  190_Reverse Bits
//
//  Created by Colin on 28/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

uint32_t reverseBits(uint32_t n) {
    for(int i = 0; i < 16; ++i) {
        int leftMask = (1 << (31 - i)), rightMask = (1 << i);
        if(((n & leftMask) == 0) ^ ((rightMask & n) == 0)) {
            int xorMask = (leftMask | rightMask);
            n ^= xorMask;
        }
    }
    return n;
}

int main(int argc, const char * argv[]) {
    cout << reverseBits(43261596) << endl;
    return 0;
}
