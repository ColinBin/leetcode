//
//  main.cpp
//  358_Rearrange String k Distance Apart
//
//  Created by Colin on 23/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

struct compareEle {
    bool operator ()(const pair<char, int> &ele1, const pair<char, int> &ele2) {
        return ele1.second < ele2.second || ele1.second == ele2.second && ele1.first < ele2.first;
    }
};

string rearrangeString(string s, int k) {
    vector<int> record(26, 0);
    if(k > 26 || k < 0)
        return "";
    if(k == 0)
        return s;
    for(const char ch : s) {
        ++record[ch - 'a'];
    }
    string result = "";
    priority_queue<pair<char, int>, vector<pair<char, int>>, compareEle> pq;
    for(int i = 0; i < 26; ++i) {
        if(record[i] != 0) {
            pq.push(make_pair(i + 'a', record[i]));
        }
    }
    while(!pq.empty()) {
        vector<pair<char, int>> temp;
        for(int i = 0; i < k; ++i) {
            if(pq.empty()) {
                if(temp.empty())
                    break;
                else
                    return "";
            }
            pair<char, int> ele = pq.top();
            pq.pop();
            result += ele.first;
            if(ele.second != 1) {
                temp.push_back(make_pair(ele.first, ele.second - 1));
            }
        }
        for(const pair<char, int> ele : temp) {
            pq.push(ele);
        }
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
