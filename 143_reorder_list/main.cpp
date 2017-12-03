//
//  main.cpp
//  143_reorder_list
//
//  Created by Colin on 16/11/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

void reorderList(ListNode* head) {
    if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
        return;
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode *middle = slow, *leftStart = head, *rightStart;
    // pointers after slow should be backwards
    ListNode *prev = slow;
    slow = slow->next;
    while(slow != nullptr) {
        ListNode *newNext = slow->next;
        slow->next = prev;
        prev = slow;
        slow = newNext;
    }
    rightStart = prev;
    // start from both sides
    
    while(leftStart != middle) {
        ListNode *nextLeft = leftStart->next, *nextRight = rightStart->next;
        leftStart->next = rightStart;
        rightStart->next = nextLeft;
        leftStart = nextLeft;
        rightStart = nextRight;
    }
    leftStart->next = nullptr;
    return;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head = new ListNode(1), *dummy = head;
    dummy->next= new ListNode(2);
    dummy = dummy->next;
    dummy->next= new ListNode(3);
    dummy = dummy->next;
    dummy->next= new ListNode(4);
    dummy = dummy->next;
    reorderList(head);
    dummy = head;
    while(dummy != nullptr) {
        cout << dummy->val << endl;
        dummy = dummy->next;
    }
    return 0;
}
