//
//  main.cpp
//  269_Alien Dictionary
//
//  Created by Colin on 19/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

// REWRITE!!!

int getIndex(const char ch) {
    return ch - 'a';
}

void buildGraph(vector<unordered_set<int>> &children, unordered_map<int, int> &indegree, vector<string> &words) {
    for(int i = 1; i < words.size(); ++i) {
        string &current = words[i];
        string &prev = words[i - 1];
        int minLen = min(current.length(), prev.length());
        for(int j = 0; j < minLen; ++j) {
            if(current[j] != prev[j]) {
                int currentInt = getIndex(current[j]), prevInt = getIndex(prev[j]);
                unordered_set<int> &childrenSet = children[prevInt];
                if(childrenSet.find(currentInt) == childrenSet.end()) {
                    childrenSet.insert(currentInt);
                    ++indegree[currentInt];
                }
                break;
            }
        }
    }
    return;
}

string alienOrder(vector<string>& words) {
    // char, indegree, next chars pointed by current one
    vector<unordered_set<int>> children(26);
    unordered_map<int, int> indegree;
    for(const string word : words) {
        for(const char ch : word) {
            if(indegree.find(getIndex(ch)) == indegree.end())
                indegree[getIndex(ch)] = 0;
        }
    }
    int wordCount = words.size();
    string result = "";
    if(wordCount == 1) {
        for(const char ch : words[0]) {
            result += ch;
        }
        return result;
    }
    buildGraph(children, indegree, words);
    queue<int> q;
    int count = 0;
    for(const auto & ele : indegree) {
        if(ele.second == 0)
            q.push(ele.first);
    }
    while(!q.empty()) {
        int currentSize = q.size();
        for(int i = 0; i < currentSize; ++i) {
            int currentCharInt = q.front();
            q.pop();
            char currentChar = currentCharInt + 'a';
            result += currentChar;
            ++count;
            for(const int child : children[currentCharInt]) {
                if(--indegree[child] == 0) {
                    q.push(child);
                }
            }
        }
    }
    
    return (count == indegree.size() ? result : "");
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
