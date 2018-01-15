//
//  main.cpp
//  25_Reverse Nodes in k-Group
//
//  Created by Colin on 14/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k == 1) return head;
    ListNode *pivot = new ListNode(-1);
    pivot->next = head;
    ListNode *prev = pivot;
    while(true) {
        ListNode *start = prev->next, *iter = start;
        ListNode *next = nullptr;
        bool done = false;
        for(int i = 0; i < k; ++i) {
            if(iter == nullptr) {
                done = true;
                break;
            }
            iter = iter->next;
        }
        next = iter;
        if(done) {
            break;
        }
        ListNode *back = start, *front = start->next;
        while(front != next) {
            ListNode *newFront = front->next;
            front->next = back;
            back = front;
            front = newFront;
        }
        prev->next = back;
        start->next = next;
        prev = start;
    }
    ListNode *newHead = pivot->next;
    delete pivot;
    return newHead;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
