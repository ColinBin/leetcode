//
//  main.cpp
//  232_Implement Queue using Stacks
//
//  Created by Colin on 28/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
        return;
    }
    
    int pop() {
        int res = peek();
        output.pop();
        return res;
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
private:
    stack<int> input, output;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
