//
//  main.cpp
//  234_Palindrome Linked List
//
//  Created by Colin on 12/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

bool isPalindrome(ListNode* head) {
    if(head == nullptr || head->next == nullptr) {
        return true;
    }
    ListNode *fast = head, *slow = head;
    ListNode *prev = nullptr;
    ListNode *newSlow;
    while(fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        newSlow = slow->next;
        slow->next = prev;
        prev = slow;
        slow = newSlow;
    }
    ListNode *rightStart = slow->next, *leftStart;
    // odd number of nodes
    if(fast->next == nullptr) {
        leftStart = prev;
    } else {
        slow->next = prev;
        leftStart = slow;
    }
    while(leftStart != nullptr) {
        if(leftStart->val != rightStart->val) {
            return false;
        }
        leftStart = leftStart->next;
        rightStart = rightStart->next;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
