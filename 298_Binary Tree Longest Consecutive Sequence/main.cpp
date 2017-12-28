//
//  main.cpp
//  298_Binary Tree Longest Consecutive Sequence
//
//  Created by Colin on 27/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;
int maxLen = 0;

int maxPathLen(TreeNode *current) {
    if(current == nullptr) return 0;
    int leftLen = maxPathLen(current->left);
    int rightLen = maxPathLen(current->right);
    int maxChildLen = 0;
    if(leftLen > 0 && current->val + 1 == current->left->val)
        maxChildLen = max(maxChildLen, leftLen);
    if(rightLen > 0 && current->val + 1 == current->right->val)
        maxChildLen = max(maxChildLen, rightLen);
    maxLen = max(maxLen, maxChildLen + 1);
    return maxChildLen + 1;
}

int longestConsecutive(TreeNode* root) {
    maxPathLen(root);
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
