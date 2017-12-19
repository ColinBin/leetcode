//
//  main.cpp
//  377_Combination Sum IV
//
//  Created by Colin on 18/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int dfs(vector<int> &nums, int target, unordered_map<int, int> &record) {
    if(target == 0) {
        return 1;
    }
    if(record.find(target) != record.end())
        return record[target];
    int count = 0;
    for(const int num : nums) {
        if(num <= target) {
            count += dfs(nums, target - num, record);
        }
    }
    record[target] = count;
    return count;
}

int combinationSum4(vector<int>& nums, int target) {
    unordered_map<int, int> record;
    return dfs(nums, target, record);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
