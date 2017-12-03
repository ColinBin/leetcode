//
//  main.cpp
//  94_inorder_tree_walk
//
//  Created by Colin on 06/11/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    // recursive
    // inorderTraversalHelper(res, root);
    
    // iterative
    stack<TreeNode *> stk;
    stk.push(root);
    while(!stk.empty()) {
        TreeNode *curr = stk.top();
        while(curr->left != nullptr) {
            stk.push(curr->left);
            curr = curr->left;
        }
        curr = stk.top();
        res.push_back(curr->val);
        stk.pop();
        if(curr->right != nullptr) {
            stk.push(curr->right);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    TreeNode *head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->right->left = new TreeNode(3);
    auto res = inorderTraversal(head);
    for(auto ele : res) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
