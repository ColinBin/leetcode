//
//  main.cpp
//  281_Zigzag Iterator
//
//  Created by Colin on 04/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty())
            q.push(make_pair(v1.begin(), v1.end()));
        if(!v2.empty())
            q.push(make_pair(v2.begin(), v2.end()));
    }
    
    int next() {
        auto current = q.front();
        q.pop();
        int res = *(current.first);
        ++(current.first);
        if(current.first != current.second) {
            q.push(current);
        }
        return res;
    }
    
    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}
