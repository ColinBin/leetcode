//
//  main.cpp
//  203_Remove Linked List Elements
//
//  Created by Colin on 19/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;
ListNode* removeElements(ListNode* head, int val) {
    ListNode *pivot = new ListNode(-1);
    pivot->next = head;
    ListNode *prev = pivot, *iter = pivot->next;
    while(iter != nullptr) {
        if(iter->val == val) {
            prev->next = iter->next;
            iter = iter->next;
        } else {
            iter = iter->next;
            prev = prev->next;
        }
    }
    return pivot->next;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
