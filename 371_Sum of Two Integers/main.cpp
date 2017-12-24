//
//  main.cpp
//  371_Sum of Two Integers
//
//  Created by Colin on 23/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int getSum(int a, int b) {
    if(a == 0)
        return b;
    while(b != 0) {
        int carry = a & b;
        a = a ^ b;
        b = (carry << 1);
    }
    return a;
}

int main(int argc, const char * argv[]) {
    cout << getSum(7, 5) << endl;
    return 0;
}
