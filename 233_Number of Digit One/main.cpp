//
//  main.cpp
//  233_Number of Digit One
//
//  Created by Colin on 03/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int getRemainOne(long A, long B) {
    if(B == 1) return A == 0 ? 0 : 1;
    if(A < B) return 0;
    else if(A >= B * 2) return B;
    else return A - B + 1;
}

// 1 * (n / 10) + (n % 10) ? 1, A ? B = if A < B then 0 else if A >= B * 10 then B else A - B + 1
// 10 * (n / 100) + (n % 100) ? 10
int countDigitOne(int n) {
    if(n <= 0) return 0;
    int shadow = n;
    long a = 1, b = 10;
    long sum = 0;
    while(shadow != 0) {
        sum += a * (n / b) + getRemainOne(n % b, a);
        shadow /= 10;
        a *= 10;
        b *= 10;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    cout << countDigitOne(1410065408) << endl;
    return 0;
}
