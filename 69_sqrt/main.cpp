//
//  main.cpp
//  69_sqrt
//
//  Created by Colin on 09/11/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
using namespace std;

int mySqrt(int x) {
    // using binary search
    // mid biased to the right
    if(x == 0)
        return 0;
    int start = 1, end = x;
    while(start < end) {
        int mid = start + (end - start + 1) / 2;
        if(mid != mid * mid / mid || mid * mid > x)
            end = mid - 1;
        else if(mid * mid == x)
            return mid;
        else
            start = mid;
    }
    return start;
}

int main(int argc, const char * argv[]) {
    cout << mySqrt(INT_MAX) << endl;
    
    return 0;
}
