//
//  main.cpp
//  169_Majority Element
//
//  Created by Colin on 09/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int currCount = 1, currNum = nums[0];
    int numCount = nums.size();
    for(int i = 1; i < numCount; ++i) {
        if(nums[i] == currNum)
            ++currCount;
        else {
            --currCount;
            if(currCount == 0) {
                currNum = nums[i];
                currCount = 1;
            }
        }
    }
    return currNum;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {3,4,5,1,1,5,6,1,1,1,4,1,1,1};
    cout << majorityElement(nums) << endl;
    return 0;
}
