//
//  main.cpp
//  406_Queue Reconstruction by Height
//
//  Created by Colin on 05/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    
    auto func = [](const pair<int, int> p1, const pair<int, int> p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    };
    sort(people.begin(), people.end(), func);
    int count = people.size();
    vector<pair<int, int>> res;
    for(int i = 0; i < count; ++i) {
        res.insert(res.begin() + people[i].second, people[i]);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> people = {
        {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}}
    };
    auto res = reconstructQueue(people);
    for(auto ele : res) {
        cout << ele.first << " " << ele.second << " - ";
    }
    cout << endl;
    return 0;
}
