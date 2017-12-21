//
//  main.cpp
//  172_Factorial Trailing Zeroes
//
//  Created by Colin on 20/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int trailingZeroes(int n) {
    int count = 0;
    while(n >= 5) {
        n /= 5;
        count += n;
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
