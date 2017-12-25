//
//  main.cpp
//  344_Reverse String
//
//  Created by Colin on 24/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

string reverseString(string s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        swap(s[left], s[right]);
        ++left;
        --right;
    }
    return s;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
