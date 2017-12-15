//
//  main.cpp
//  313_Super Ugly Number
//
//  Created by Colin on 14/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compareEle {
    bool operator()(const pair<int, int> ele1, const pair<int, int> ele2) {
        return ele1.first > ele2.first;
    }
};

int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> record;
    record.push_back(1);
    --n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compareEle> minHeap;
    for(const int prime : primes) {
        minHeap.push(make_pair(prime, 0));
    }
    while(n != 0) {
        pair<int, int> minEle = minHeap.top();
        minHeap.pop();
        if(minEle.first != record.back()) {
            record.push_back(minEle.first);
        }
        minHeap.push({(minEle.first / record[minEle.second]) * record[minEle.second + 1], minEle.second + 1});
        --n;
    }
    return record.back();
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
