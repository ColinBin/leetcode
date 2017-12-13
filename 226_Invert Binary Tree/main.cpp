//
//  main.cpp
//  226_Invert Binary Tree
//
//  Created by Colin on 12/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr)
        return nullptr;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
