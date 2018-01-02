//
//  main.cpp
//  572_Subtree of Another Tree
//
//  Created by Colin on 31/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool treeEqual(TreeNode *s, TreeNode *t) {
    if(s == nullptr && t == nullptr) return true;
    if(s == nullptr || t == nullptr || s->val != t->val) return false;
    return treeEqual(s->left, t->left) && treeEqual(s->right, t->right);
}

bool isSubtree(TreeNode* s, TreeNode* t) {
    if(s == nullptr) return false;
    return treeEqual(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
