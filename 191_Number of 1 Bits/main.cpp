//
//  main.cpp
//  191_Number of 1 Bits
//
//  Created by Colin on 09/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    for(int i = 0; i < 32; ++i) {
        if(n & 0x01)
            ++count;
        n >>= 1;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    cout << hammingWeight(11) << endl;
    return 0;
}
