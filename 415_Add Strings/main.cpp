//
//  main.cpp
//  415_Add Strings
//
//  Created by Colin on 31/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

string addStrings(string num1, string num2) {
    int numLen1 = num1.length(), numLen2 = num2.length();
    if(numLen1 == 0) return num2;
    if(numLen2 == 0) return num1;
    bool carry = false;
    if(numLen1 < numLen2) {
        num1 = string(numLen2 - numLen1, '0') + num1;
    } else {
        num2 = string(numLen1 - numLen2, '0') + num2;
    }
    int len = num1.length();
    string result = "";
    for(int i = len - 1; i >= 0; --i) {
        int digit1 = num1[i] - '0',  digit2 = num2[i] - '0';
        int currentSum = digit1 + digit2 + carry;
        result += (currentSum) % 10 + '0';
        carry = (digit1 + digit2 + carry) >= 10;
        
    }
    if(carry)
        result += "1";
    return string(result.rbegin(), result.rend());
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
