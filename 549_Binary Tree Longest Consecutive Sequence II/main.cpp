//
//  main.cpp
//  549_Binary Tree Longest Consecutive Sequence II
//
//  Created by Colin on 27/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;
int maxLen = 0;

void helper(TreeNode *current, int &increaseMax, int &decreaseMax) {
    if(current == nullptr) {
        increaseMax = decreaseMax = 0;
        return;
    }
    int leftIncreaseMax, leftDecreaseMax, rightIncreaseMax, rightDecreaseMax;
    helper(current->left, leftIncreaseMax, leftDecreaseMax);
    helper(current->right, rightIncreaseMax, rightDecreaseMax);
    int childIncreaseMax = 0, childDecreaseMax = 0;
    if(leftIncreaseMax > 0 && current->val + 1 == current->left->val) {
        childIncreaseMax = max(childIncreaseMax, leftIncreaseMax);
    } else if(rightIncreaseMax > 0 && current->val + 1 == current->right->val) {
        childIncreaseMax = max(childIncreaseMax, rightIncreaseMax);
    }
    if(leftDecreaseMax > 0 && current->val - 1 == current->left->val) {
        childDecreaseMax = max(childDecreaseMax, leftDecreaseMax);
    } else if(rightDecreaseMax > 0 && current->val - 1 == current->right->val){
        childDecreaseMax = max(childDecreaseMax, rightDecreaseMax);
    }
    increaseMax = childIncreaseMax + 1;
    decreaseMax = childDecreaseMax + 1;
    maxLen = max(maxLen, childIncreaseMax + childDecreaseMax + 1);
    return;
}

int longestConsecutive(TreeNode* root) {
    int increaseDummy, decreaseDummy;
    helper(root, increaseDummy, decreaseDummy);
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
