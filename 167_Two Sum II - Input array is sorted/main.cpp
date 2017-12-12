//
//  main.cpp
//  167_Two Sum II - Input array is sorted
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>

vector<int> twoSum(vector<int>& numbers, int target) {
    int numCount = numbers.size();
    int left = 0, right = numCount - 1;
    vector<int> res;
    while(left < right) {
        int current = numbers[left] + numbers[right];
        if(current == target) {
            res.push_back(left + 1);
            res.push_back(right + 1);
            return res;
        } else if(current < target) {
            ++left;
        } else {
            --right;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
