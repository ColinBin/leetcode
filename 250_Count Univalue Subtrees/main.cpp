//
//  main.cpp
//  250_Count Univalue Subtrees
//
//  Created by Colin on 21/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "basic_ds.hpp"

using namespace std;

int total = 0;

bool dfs(TreeNode *root) {
    if(root == nullptr)
        return true;
    bool left = dfs(root->left);
    bool right = dfs(root->right);
    if(left && right) {
        bool invalid = ((root->left != nullptr && root->left->val != root->val) ||
                        (root->right != nullptr && root->right->val != root->val));
        if(!invalid) {
            ++total;
            return true;
        }
        
    }
    return false;
}

int countUnivalSubtrees(TreeNode* root) {
    dfs(root);
    return total;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
