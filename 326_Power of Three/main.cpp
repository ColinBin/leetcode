//
//  main.cpp
//  326_Power of Three
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isPowerOfThree(int n) {
    if(n <= 0)
        return false;
    while(n != 1) {
        if(n % 3 != 0) {
            return false;
        }
        n /= 3;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
