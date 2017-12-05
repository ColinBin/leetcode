//
//  main.cpp
//  263_Ugly Number
//
//  Created by Colin on 05/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>

using namespace std;

bool isUgly(int num) {
    if(num <= 0)
        return false;
    while(num != 1) {
        bool match = false;
        if(num % 2 == 0) {
            match = true;
            num /= 2;
        }
        if(num % 3 == 0) {
            match = true;
            num /= 3;
        }
        if(num % 5 == 0) {
            match = true;
            num /= 5;
        }
        if(!match) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    cout << isUgly(2341) << endl;
    return 0;
}
