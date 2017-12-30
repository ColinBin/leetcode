//
//  main.cpp
//  274_H-Index
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int hIndex(vector<int>& citations) {
    int size = citations.size();
    vector<int> bucket(size + 2, 0);
    for(const int citation : citations) {
        if(citation > size)
            ++bucket[size + 1];
        else
            ++bucket[citation];
    }
    int result = 0;
    for(int i = size; i >= 0; --i) {
        bucket[i] += bucket[i + 1];
        if(bucket[i] >= i) {
            result = i;
            break;
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
