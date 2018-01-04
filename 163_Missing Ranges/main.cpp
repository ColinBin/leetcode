//
//  main.cpp
//  163_Missing Ranges
//
//  Created by Colin on 03/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    int numCount = nums.size();
    vector<string> res;
    if(numCount == 0) {
        if(lower == upper)
            res.push_back(to_string(lower));
        else
            res.push_back(to_string(lower) + "->" + to_string(upper));
        return res;
    }
    int start = lower;
    int i = 0;
    while(i < numCount) {
        int current = nums[i];
        if(current == start) {
            ++start;
        } else {
            if(start == current - 1) {
                res.push_back(to_string(start));
            } else {
                res.push_back(to_string(start) + "->" + to_string(current - 1));
            }
            start = current + 1;
        }
        ++i;
        // deal with duplicates
        while(i < numCount && nums[i] == current) ++i;
    }
    if(start == upper) {
        res.push_back(to_string(upper));
    } else if(start > lower && start < upper) {
        res.push_back(to_string(start) + "->" + to_string(upper));
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
