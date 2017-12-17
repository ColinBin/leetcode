//
//  main.cpp
//  433_Minimum Genetic Mutation
//
//  Created by Colin on 16/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> genes(bank.begin(), bank.end());
    unordered_set<string> found;
    const vector<char> mutations = {'A', 'G', 'C', 'T'};
    // end not in the bank
    if(genes.find(end) == genes.end())
        return -1;
    queue<string> bfs;
    bfs.push(start);
    found.insert(start);
    int level = 0;
    while(!bfs.empty()) {
        ++level;
        int currentLevelCount = bfs.size();
        for(int i = 0; i < currentLevelCount; ++i) {
            string current = bfs.front();
            bfs.pop();
            // check reachable nodes from current string
            for(int i = 0; i < 8; ++i) {
                string temp = current;
                for(const char ch : mutations) {
                    temp[i] = ch;
                    // since the end must be in the bank
                    if(temp == end)
                        return level;
                    if(genes.find(temp) != genes.end() && found.find(temp) == found.end()) {
                        bfs.push(temp);
                        found.insert(temp);
                    }
                }
            }
        }
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
