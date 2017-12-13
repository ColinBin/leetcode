//
//  basic_ds.hpp
//  leetcode
//
//  Created by Colin on 12/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#ifndef basic_ds_hpp
#define basic_ds_hpp

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#endif /* basic_ds_hpp */
