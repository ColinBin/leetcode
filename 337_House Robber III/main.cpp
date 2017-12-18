//
//  main.cpp
//  337_House Robber III
//
//  Created by Colin on 17/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include "../basic_ds.hpp"

using namespace std;

unordered_map<TreeNode *, int> dp;

int rob(TreeNode* root) {
    if(root == nullptr) return 0;
    if(dp.find(root) != dp.end())
        return dp[root];
    int llgc = 0, lrgc = 0, rlgc = 0, rrgc = 0;
    int leftChild = rob(root->left);
    if(root->left != nullptr) {
        llgc = rob(root->left->left);
        lrgc = rob(root->left->right);
    }
    int rightChild = rob(root->right);
    if(root->right != nullptr) {
        rlgc = rob(root->right->left);
        rrgc = rob(root->right->right);
    }
    dp[root] = max(root->val + llgc + lrgc + rlgc + rrgc, leftChild + rightChild);
    return dp[root];
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
