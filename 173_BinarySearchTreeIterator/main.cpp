//
//  main.cpp
//  173_BinarySearchTreeIterator
//
//  Created by Colin on 03/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAllLeft(root);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode *current = stk.top();
        stk.pop();
        if(current->right != nullptr)
            pushAllLeft(current->right);
        return current->val;
    }
private:
    void pushAllLeft(TreeNode *root) {
        while(root != nullptr) {
            stk.push(root);
            root = root->left;
        }
    }
    
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
