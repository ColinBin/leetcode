//
//  main.cpp
//  235_Lowest Common Ancestor of a Binary Search Tree
//
//  Created by Colin on 09/12/2017.
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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int val1 = min(p->val, q->val), val2 = max(p->val, q->val);
    while(root != p && root != q) {
        if(root->val > val1 && root->val < val2)
            return root;
        if(root->val < val1)
            root = root->right;
        if(root->val > val2) {
            root = root->left;
        }
    }
    return root;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
