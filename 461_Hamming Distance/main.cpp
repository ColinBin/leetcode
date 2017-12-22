//
//  main.cpp
//  461_Hamming Distance
//
//  Created by Colin on 21/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "basic_ds.hpp"

using namespace std;

int hammingDistance(int x, int y) {
    int z = x ^ y;
    int count = 0;
    for(int i = 0; i < 32; ++i) {
        if(z & 0x01)
            ++count;
        z >>= 1;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
