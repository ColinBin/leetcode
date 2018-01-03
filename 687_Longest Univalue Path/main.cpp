//
//  main.cpp
//  687_Longest Univalue Path
//
//  Created by Colin on 02/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxLen = 0;

int helper(TreeNode *current) {
    if(current == nullptr) return 0;
    int leftMaxLen = helper(current->left), rightMaxLen = helper(current->right);
    int currentLen = 0;
    int maxPathLen = 0;
    if(current->left != nullptr && current->left->val == current->val) {
        currentLen += leftMaxLen + 1;
        maxPathLen = leftMaxLen + 1;
    }
    
    if(current->right != nullptr && current->right->val == current->val) {
        currentLen += rightMaxLen + 1;
        maxPathLen = max(maxPathLen, rightMaxLen + 1);
    }
    maxLen = max(maxLen, currentLen);
    return maxPathLen;
}

int longestUnivaluePath(TreeNode* root) {
    helper(root);
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
