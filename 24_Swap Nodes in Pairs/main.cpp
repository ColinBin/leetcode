//
//  main.cpp
//  24_Swap Nodes in Pairs
//
//  Created by Colin on 14/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

ListNode* swapPairs(ListNode* head) {
    ListNode *pivot = new ListNode(-1);
    pivot->next = head;
    ListNode *prev = pivot;
    while(prev->next != nullptr && prev->next->next != nullptr) {
        ListNode *first = prev->next, *second = prev->next->next;
        prev->next = second;
        first->next = second->next;
        second->next = first;
        prev = first;
    }
    ListNode *newHead = pivot->next;
    delete pivot;
    return newHead;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
