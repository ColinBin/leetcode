//
//  main.cpp
//  654_Maximum Binary Tree
//
//  Created by Colin on 23/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    int numCount = nums.size();
    if(numCount == 0)
        return nullptr;
    vector<TreeNode *> stk;
    for(int i = 0; i < numCount; ++i) {
        int current = nums[i];
        TreeNode *newNode = new TreeNode(current);
        while(!stk.empty() && stk.back()->val < current) {
            newNode->left = stk.back();
            stk.pop_back();
        }
        if(!stk.empty()) {
            stk.back()->right = newNode;
        }
        stk.push_back(newNode);
    }
    return stk.front();
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
