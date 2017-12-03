//
//  main.cpp
//  698_Partition_to_K_Equal
//
//  Created by Colin on 14/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool dfs(vector<int> &nums, int index, int remain, const int targetSum, int &count, const int targetCount) {
    cout << index << " " << remain << " " << count << endl;
    if(remain == 0) {
        ++count;
        if(count == targetCount) {
            return true;
        }
        remain = targetSum;
    }
    for(int i = index; i < nums.size(); ++i) {
        if(nums[i] <= remain) {
            if(dfs(nums, i + 1, remain - nums[i], targetSum, count, targetCount)) {
                return true;
            }
        }
    }
    return false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0;
    int numsCount = nums.size();
    if(k > numsCount) {
        return false;
    }
    for(auto ele : nums) {
        sum += ele;
    }
    if(sum % k != 0) {
        return false;
    }
    int target = sum / k;
    if(dfs(nums, 0, target, target, 0, k)) {
        return true;
    }
    return false;
}


int main(int argc, const char * argv[]) {
    vector<int> nums = {4,3,2,3,5,2,1};
    int k = 4;
    cout << canPartitionKSubsets(nums, k) << endl;
    return 0;
}
