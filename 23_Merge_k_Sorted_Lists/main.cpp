//
//  main.cpp
//  23_Merge_k_Sorted_Lists
//
//  Created by Colin on 12/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class myComparsion {
public:
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.first > rhs.first;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    int listCount = lists.size();
    if(listCount == 0) return nullptr;
    if(listCount == 1) return lists[0];
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparsion> min_heap;
    // initialize the queue from first elements from k lists
    for(int i = 0; i < listCount; ++i) {
        if(lists[i] != nullptr) {
            min_heap.push(make_pair(lists[i]->val, i));
            lists[i] = lists[i]->next;
        }
    }
    ListNode *pivot = new ListNode(-1), *dummy = pivot;
    while(!min_heap.empty()) {
        auto current = min_heap.top();
        int index = current.second;
        int value = current.first;
        dummy->next = new ListNode(value);
        dummy = dummy->next;
        min_heap.pop();
        if(lists[index] != nullptr) {
            min_heap.push(make_pair(lists[index]->val, index));
            lists[index] = lists[index]->next;
        }
    }
    return pivot->next;
}

int main(int argc, const char * argv[]) {
    return 0;
}
