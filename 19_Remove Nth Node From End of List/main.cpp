//
//  main.cpp
//  19_Remove Nth Node From End of List
//
//  Created by Colin on 09/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *front = dummy, *prev = dummy;
    for(int i = 0; i < n; ++i) {
        front = front->next;
    }
    while(front->next != nullptr) {
        front = front->next;
        prev = prev->next;
    }
    
    ListNode *toRemove = prev->next;
    prev->next = prev->next->next;
    delete toRemove;
    
    return dummy->next;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
