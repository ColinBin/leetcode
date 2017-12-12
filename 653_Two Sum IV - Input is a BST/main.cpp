//
//  main.cpp
//  653_Two Sum IV - Input is a BST
//
//  Created by Colin on 11/12/2017.
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

bool findTarget(TreeNode* root, int k) {
    if(root == nullptr)
        return false;
    vector<int> nodes;
    TreeNode *dummy = root;
    while(dummy != nullptr) {
        if(dummy->left == nullptr) {
            nodes.push_back(dummy->val);
            dummy = dummy->right;
        } else {
            TreeNode *predecessor = dummy->left;
            while(predecessor->right != nullptr && predecessor->right != dummy) {
                predecessor = predecessor->right;
            }
            if(predecessor->right != dummy) {
                predecessor->right = dummy;
                dummy = dummy->left;
            } else {
                nodes.push_back(dummy->val);
                predecessor->right = nullptr;
                dummy = dummy->right;
            }
        }
    }
    int nodeCount = nodes.size();
    int left = 0, right = nodeCount - 1;
    while(left < right) {
        if(nodes[left] + nodes[right] > k) {
            --right;
        } else if(nodes[left] + nodes[right] < k) {
            ++left;
        } else {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
