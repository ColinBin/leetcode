//
//  main.cpp
//  670_Maximum Swap
//
//  Created by Colin on 02/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maximumSwap(int num) {
    if(num <= 11) return num;
    vector<int> digits;
    while(num != 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    vector<int> bucket(10, INT_MAX);
    for(int i = 0; i < digits.size(); ++i) {
        if(bucket[digits[i]] == INT_MAX)
            bucket[digits[i]] = i;
    }
    int maxDigit = 9;
    for(int i = digits.size() - 1; i >= 0; --i) {
        bool done = false;
        for(int j = maxDigit; j > digits[i]; --j) {
            if(i > bucket[j]) {
                swap(digits[i], digits[bucket[j]]);
                done = true;
                break;
            }
        }
        if(done) break;
        maxDigit = digits[i];
    }
    num = 0;
    for(int i = digits.size() - 1; i >= 0; --i) {
        num = num * 10 + digits[i];
    }
    return num;
}

int main(int argc, const char * argv[]) {
    cout << maximumSwap(7236) << endl;
    return 0;
}
