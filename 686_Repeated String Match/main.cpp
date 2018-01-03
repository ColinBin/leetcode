//
//  main.cpp
//  686_Repeated String Match
//
//  Created by Colin on 31/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int repeatedStringMatch(string A, string B) {
    int lenA = A.length(), lenB = B.length();
    int times = (lenB + lenA - 1) / lenA + 1;
    string full = "";
    for(int i = 0; i < times; ++i) {
        full += A;
    }
    auto index = full.find(B);
    if(index == string::npos) return -1;
    if(index + lenB <= lenA * (times - 1)) return times - 1;
    return times;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
