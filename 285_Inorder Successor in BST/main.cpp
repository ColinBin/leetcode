//
//  main.cpp
//  285_Inorder Successor in BST
//
//  Created by Colin on 12/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(root == nullptr || p == nullptr)
        return nullptr;
    if(p->right != nullptr) {
        TreeNode *potential = p->right;
        while(potential->left != nullptr)
            potential = potential->left;
        return potential;
    }
    TreeNode *dummy = root, *candidate = nullptr;
    while(dummy != p) {
        if(dummy->val > p->val) {
            candidate = dummy;
            dummy = dummy->left;
        } else if(dummy->val < p->val){
            dummy = dummy->right;
        }
    }
    return candidate;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
