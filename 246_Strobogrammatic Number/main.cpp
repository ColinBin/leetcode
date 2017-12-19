//
//  main.cpp
//  246_Strobogrammatic Number
//
//  Created by Colin on 18/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool isStrobogrammatic(string num) {
    unordered_map<char, char> dict = {
        {'1', '1'}, {'2', '#'}, {3, '#'}, {'4', '#'}, {'5', '#'}, {'6', '9'}, {'7', '#'}, {'8', '8'}, {'9', '6'}, {'0', '0'}
    };
    int numLen = num.length();
    int left = 0, right = numLen - 1;
    while(left <= right) {
        if(num[right] != dict[num[left]]) {
            return false;
        }
        ++left;
        --right;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
