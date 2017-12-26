//
//  main.cpp
//  367_Valid Perfect Square
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isPerfectSquare(int num) {
    int left = 1, right = num;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int current = mid * mid;
        if(current == num)
            return true;
        if(current / mid != mid || current > num) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    cout << isPerfectSquare(16) << endl;
    return 0;
}
