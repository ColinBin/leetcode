//
//  main.cpp
//  532_K-diff Pairs in an Array
//
//  Created by Colin on 06/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int findPairs(vector<int>& nums, int k) {
    unordered_set<int> checked;
    unordered_set<int> record;
    if(k < 0) return 0;
    int count = 0;
    for(const int num : nums) {
        
        if(record.find(num - k) != record.end() && checked.find(num - k) == checked.end()) {
            ++count;
            checked.insert(num - k);
        }
        if(record.find(num + k) != record.end() && checked.find(num) == checked.end()) {
            ++count;
            checked.insert(num);
        }
        if(record.find(num) != record.end())
            record.insert(num);
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
