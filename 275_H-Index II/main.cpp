//
//  main.cpp
//  275_H-Index II
//
//  Created by Colin on 29/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int hIndex(vector<int>& citations) {
    
    int size = citations.size();
    if(size == 0 || citations.back() == 0)
        return 0;
    int left = 0, right = size - 1;
    while(left < right) {
        int mid = left + (right - left) / 2;
        bool valid = (citations[mid] >= (size - mid));
        if(valid) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return size - left;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {0,0};
    cout << hIndex(a) << endl;
    return 0;
}
