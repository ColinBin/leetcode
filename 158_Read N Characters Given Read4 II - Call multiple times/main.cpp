//
//  main.cpp
//  158_Read N Characters Given Read4 II - Call multiple times
//
//  Created by Colin on 28/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while(i < n) {
            if(bufferPtr >= localCnt) {
                localCnt = read4(localBuffer);
                bufferPtr = 0;
                if(localCnt == 0)
                    break;
            }
            buf[i++] = localBuffer[bufferPtr++];
        }
        return i;
    }
private:
    char localBuffer[4];
    int localCnt = 0;
    int bufferPtr = 0;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
