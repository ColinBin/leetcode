//
//  main.cpp
//  165_CompareVersionNumbers
//
//  Created by Colin on 03/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int compareVersion(string version1, string version2) {
    int len1 = version1.length(), len2 = version2.length();
    int index1 = 0, index2 = 0;
    while(index1 < len1 && index2 < len2) {
        long val1 = 0;
        while(index1 < len1 && version1[index1] != '.') {
            val1 = val1 * 10 + (version1[index1] - '0');
            ++index1;
        }
        long val2 = 0;
        while(index2 < len2 && version2[index2] != '.') {
            val2 = val2 * 10 + (version2[index2] - '0');
            ++index2;
        }
        if(val1 < val2)
            return -1;
        else if(val1 > val2)
            return 1;
        else if(index1 == len1 && index2 == len2)
            return 0;
        // current value equal, check if either one is exhausted
        if(index1 == len1) {
            while(index2 != len2) {
                if(version2[index2] != '.' && version2[index2] != '0')
                    return -1;
                ++index2;
            }
            return 0;
        }
        if(index2 == len2) {
            while(index1 != len1) {
                if(version1[index1] != '.' && version1[index1] != '0')
                    return 1;
                ++index1;
            }
            return 0;
        }
        
        // both not exhausted, jump over .
        ++index1;
        ++index2;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    cout << compareVersion("1.13", "1.14") << endl;
    return 0;
}
