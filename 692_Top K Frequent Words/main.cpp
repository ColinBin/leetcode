//
//  main.cpp
//  692_Top K Frequent Words
//
//  Created by Colin on 14/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct compareEle {
    bool operator()(const pair<string, int> &word1, const pair<string, int> &word2) {
        return word1.second > word2.second || (word1.second == word2.second && word1.first < word2.first);
    }
};

vector<string> topKFrequent(vector<string>& words, int k) {
    priority_queue<pair<string, int>, vector<pair<string, int>>, compareEle> minHeap;
    unordered_map<string, int> record;
    for(const string &word : words) {
        ++record[word];
    }
    for(const auto &data : record) {
        if(minHeap.size() < k) {
            minHeap.push(data);
        } else {
            const auto topElement = minHeap.top();
            if(data.second > topElement.second || (data.second == topElement.second && data.first < topElement.first)) {
                minHeap.pop();
                minHeap.push(data);
            }
        }
    }
    vector<string> result;
    while(!minHeap.empty()) {
        result.push_back(minHeap.top().first);
        minHeap.pop();
    }
    reverse(result.begin(), result.end());
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
