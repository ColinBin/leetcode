//
//  main.cpp
//  282_Expression Add Operators
//
//  Created by Colin on 30/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void helper(vector<string> &res, string tempList, const string &num, int index, long currentVal, const int target, int currentProduct) {
    if(index == num.length()) {
        if(currentVal == target)
            res.push_back(tempList);
        return;
    }
    long value = 0;
    string valStr = "";
    for(int i = index; i < num.length(); ++i) {
        int digit = num[i] - '0';
        if(num[index] == '0' && i != index) break;
        value = value * 10 + digit;
        valStr += num[i];
        if(index == 0) {
            helper(res, valStr, num, i + 1, value, target, value);
        } else {
            helper(res, tempList + "+" + valStr, num, i + 1, currentVal + value, target, value);
            helper(res, tempList + "-" + valStr, num, i + 1, currentVal - value, target, -value);
            helper(res, tempList + "*" + valStr, num, i + 1, currentVal - currentProduct + currentProduct * value, target, currentProduct * value);
        }
    }
    return;
}

vector<string> addOperators(string num, int target) {
    vector<string> res;
    helper(res, "", num, 0, 0, target, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
