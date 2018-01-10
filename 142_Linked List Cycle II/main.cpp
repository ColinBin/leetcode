//
//  main.cpp
//  142_Linked List Cycle II
//
//  Created by Colin on 09/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while(fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast) {
            fast = head;
            while(fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return nullptr;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
