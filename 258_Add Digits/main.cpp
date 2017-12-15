//
//  main.cpp
//  258_Add Digits
//
//  Created by Colin on 14/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>

using namespace std;

int addDigits(int num) {
    while(num >= 10) {
        int newNum = 0;
        while(num > 0) {
            newNum += num % 10;
            num /= 10;
        }
        num = newNum;
    }
    return num;
}

int main(int argc, const char * argv[]) {
    cout << addDigits(38) << endl;
    return 0;
}
