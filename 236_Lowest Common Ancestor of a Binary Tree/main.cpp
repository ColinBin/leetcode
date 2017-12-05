//
//  main.cpp
//  236_Lowest Common Ancestor of a Binary Tree
//
//  Created by Colin on 05/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr || root == p || root == q)
        return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if(left != nullptr && right != nullptr)
        return root;
    if(left == nullptr)
        return right;
    else
        return left;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
