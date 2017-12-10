//
//  main.cpp
//  229_Majority Element II
//
//  Created by Colin on 09/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    vector<int> res;
    int numsCount = nums.size();
    if(numsCount == 0)
        return res;
    int num1 = 0, num2 = 0, count1 = 0, count2 = 0;
    for(const int num : nums) {
        if(num == num1)
            ++count1;
        else if (num == num2)
            ++count2;
        else if(count1 == 0) {
            num1 = num;
            count1 = 1;
        } else if(count2 == 0) {
            num2 = num;
            count2 = 1;
        } else {
            --count1;
            --count2;
        }
    }
    if(count1 > 0 && count(nums.begin(), nums.end(), num1) > numsCount / 3)
        res.push_back(num1);
    if(count2 > 0 && count(nums.begin(), nums.end(), num2) > numsCount / 3)
        res.push_back(num2);
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,1,3,4,1,4,4,1,1,4,5};
    auto res = majorityElement(nums);
    for(int ele : res)
        cout << ele << " ";
    cout << endl;
    return 0;
}
