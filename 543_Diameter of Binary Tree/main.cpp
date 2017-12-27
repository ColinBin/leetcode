//
//  main.cpp
//  543_Diameter of Binary Tree
//
//  Created by Colin on 26/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int maxLen = 0;

int helper(TreeNode *root) {
    if(root == nullptr)
        return -1;
    int left = helper(root->left) + 1;
    int right = helper(root->right) + 1;
    maxLen = max(maxLen, left + right);
    return max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    helper(root);
    return maxLen;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
