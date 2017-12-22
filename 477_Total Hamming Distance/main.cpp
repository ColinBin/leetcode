//
//  main.cpp
//  477_Total Hamming Distance
//
//  Created by Colin on 21/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "basic_ds.hpp"

using namespace std;

int totalHammingDistance(vector<int>& nums) {
    vector<int> counts(32, 0);
    int total = 0;
    for(int num : nums) {
        for(int i = 0; i < 32; ++i) {
            if(num & 0x01) {
                ++counts[i];
            }
            num >>= 1;
        }
    }
    for(const int count : counts) {
        total += count * (nums.size() - count);
    }
    return total;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
