//
//  main.cpp
//  157_Read N Characters Given Read4
//
//  Created by Colin on 28/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int read4(char *buf);

/**
 * @param buf Destination buffer
 * @param n   Maximum number of characters to read
 * @return    The number of characters read
 */


int read(char *buf, int n) {
    int count = 0;
    char localBuffer[4] = "";
    // chars in file > n or chars in file < n
    while(n != 0) {
        int currentCnt = read4(localBuffer);
        if(currentCnt >= n) {
            strncpy(buf + count, localBuffer, n);
            n = 0;
            count += n;
        } else {
            strncpy(buf + count, localBuffer, currentCnt);
            count += currentCnt;
            n -= currentCnt;
            if(currentCnt < 4)
                break;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
