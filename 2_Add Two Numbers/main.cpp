//
//  main.cpp
//  2_Add Two Numbers
//
//  Created by Colin on 14/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *pivot = new ListNode(-1), *current = pivot;
    int carry = 0;
    while(l1 != nullptr || l2 != nullptr) {
        int first = 0, second = 0;
        if(l1 != nullptr) {
            first = l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr) {
            second = l2->val;
            l2 = l2->next;
        }
        int sum = first + second + carry;
        current->next = new ListNode(sum % 10);
        carry = sum > 9;
        current = current->next;
    }
    if(carry == 1) {
        current->next = new ListNode(1);
    }
    return pivot->next;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
