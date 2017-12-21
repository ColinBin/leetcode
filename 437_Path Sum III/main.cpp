//
//  main.cpp
//  437_Path Sum III
//
//  Created by Colin on 20/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include "../basic_ds.hpp"

using namespace std;

int pathSumHelper(TreeNode *root, unordered_map<int, int> &prefix, int sofar, const int target) {
    if(root == nullptr)
        return 0;
    sofar += root->val;
    int remain = sofar - target;
    int count = 0;
    if(prefix.find(remain) != prefix.end()) {
        count += prefix[remain];
    }
    ++prefix[sofar];
    count += pathSumHelper(root->left, prefix, sofar, target) + pathSumHelper(root->right, prefix, sofar, target);
    --prefix[sofar];
    return count;
}

int pathSum(TreeNode* root, int sum) {
    unordered_map<int, int> prefix;
    prefix[0] = 1;
    return pathSumHelper(root, prefix, 0, sum);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
