//
//  main.cpp
//  328_Odd Even Linked List
//
//  Created by Colin on 11/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr)
        return head;
    ListNode *oddHead = head, *evenHead = head->next;
    ListNode *oddTail = oddHead, *evenTail = evenHead;
    ListNode *dummy = head->next->next;
    while(dummy != nullptr) {
        oddTail->next = dummy;
        oddTail = dummy;
        dummy = dummy->next;
        if(dummy != nullptr) {
            evenTail->next = dummy;
            evenTail = dummy;
            dummy = dummy->next;
        }
    }
    oddTail->next = evenHead;
    evenTail->next = nullptr;
    return oddHead;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
