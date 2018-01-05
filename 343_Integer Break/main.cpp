//
//  main.cpp
//  343_Integer Break
//
//  Created by Colin on 04/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int integerBreak(int n) {
    if(n == 2) return 1;
    else if(n == 3) return 2;
    int twos = 0, threes = 0;
    twos = n / 2;
    if(n % 2) {
        --twos;
        ++threes;
    }
    threes = threes + twos / 3 * 2;
    twos = twos % 3;
    return pow(2, twos) * pow(3, threes);
}

int main(int argc, const char * argv[]) {
    cout << integerBreak(10) << endl;
    return 0;
}
