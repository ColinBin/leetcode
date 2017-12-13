//
//  main.cpp
//  454_4Sum II
//
//  Created by Colin on 12/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    int aLen = A.size(), bLen = B.size(), cLen = C.size(), dLen = D.size();
    if(!aLen || !bLen || !cLen || !dLen)
        return 0;
    unordered_map<int, int> record;
    for(const int a : A) {
        for(const int b : B)
            ++record[a + b];
    }
    int count = 0;
    for(const int c : C) {
        for(const int d : D) {
            count += record[0 - (c + d)];
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
