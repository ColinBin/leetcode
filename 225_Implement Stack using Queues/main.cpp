//
//  main.cpp
//  225_Implement Stack using Queues
//
//  Created by Colin on 28/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        int size = q.size();
        q.push(x);
        for(int i = 0; i < size; ++i) {
            int ele = q.front();
            q.pop();
            q.push(ele);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ele = q.front();
        q.pop();
        return ele;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
private:
    queue<int> q;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}

