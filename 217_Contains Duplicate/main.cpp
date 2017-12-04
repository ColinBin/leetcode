//
//  main.cpp
//  217_Contains Duplicate
//
//  Created by Colin on 04/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    set<int> records;
    for(int num : nums) {
        if(records.find(num) != records.end())
            return true;
        records.insert(num);
    }
    return false;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,2,3,4,4,5,6,8};
    cout << containsDuplicate(nums) << endl;
    return 0;
}
