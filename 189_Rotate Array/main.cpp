//
//  main.cpp
//  189_Rotate Array
//
//  Created by Colin on 10/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using std::vector;
using std::cout; using std::endl;
using std::reverse;

void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
    return ;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 5);
    for(auto ele : nums)
        cout << ele << " ";
    cout << endl;
    return 0;
}
