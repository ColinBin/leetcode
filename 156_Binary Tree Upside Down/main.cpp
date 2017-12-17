//
//  main.cpp
//  156_Binary Tree Upside Down
//
//  Created by Colin on 16/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"
#include <stack>

using namespace std;

TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if(root == nullptr)
        return nullptr;
    stack<TreeNode *> stk;
    TreeNode *dummy = root;
    while(dummy != nullptr) {
        stk.push(dummy);
        dummy = dummy->left;
    }
    TreeNode *newRoot = stk.top(), *prevRoot = newRoot;
    stk.pop();
    while(!stk.empty()) {
        TreeNode *current = stk.top();
        stk.pop();
        prevRoot->right = current;
        prevRoot->left = current->right;
        prevRoot = current;
    }
    prevRoot->left = prevRoot->right = nullptr;
    return newRoot;
}
TreeNode* upsideDownBinaryTreeRecursive(TreeNode* root) {
    if(root == nullptr || root->left == nullptr) {
        return root;
    }
    TreeNode *newRoot = upsideDownBinaryTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = root->right = nullptr;
    return newRoot;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
