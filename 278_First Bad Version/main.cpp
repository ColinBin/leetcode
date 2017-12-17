//
//  main.cpp
//  278_First Bad Version
//
//  Created by Colin on 16/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
using namespace std;

bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1, right = n;
    while(left != right) {
        int mid = left + (right - left) / 2;
        if(isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
