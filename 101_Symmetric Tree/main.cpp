//
//  main.cpp
//  101_Symmetric Tree
//
//  Created by Colin on 21/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool twoSymmetric(TreeNode *left, TreeNode *right) {
    if(left == nullptr && right == nullptr) return true;
    if(left == nullptr || right == nullptr) return false;
    if(left->val != right->val) return false;
    return twoSymmetric(left->left, right->right) && twoSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == nullptr) return true;
    return twoSymmetric(root->left, root->right);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
