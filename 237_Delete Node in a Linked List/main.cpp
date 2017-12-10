//
//  main.cpp
//  237_Delete Node in a Linked List
//
//  Created by Colin on 09/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
    ListNode *next = node->next;
    while(next->next != nullptr) {
        swap(node->val, next->val);
        node = next;
        next = next->next;
    }
    swap(node->val, next->val);
    delete next;
    node->next = nullptr;
    return ;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
