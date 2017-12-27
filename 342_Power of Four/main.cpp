//
//  main.cpp
//  342_Power of Four
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isPowerOfFour(int num) {
    return num > 0 && (num & (num - 1) == 0) && (num & 0x55555555) != 0;
    if(num <= 0)
        return false;
    while(true) {
        int current = num & 0x3;
        if(current == 1) {
            num >>= 2;
            return num == 0;
        } else if(current == 0){
            num >>= 2;
        } else {
            return false;
        }
    }
}

int main(int argc, const char * argv[]) {
    cout << isPowerOfFour(64) << endl;
    return 0;
}
