//
//  main.cpp
//  332_Reconstruct Itinerary
//
//  Created by Colin on 06/01/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void dfs(unordered_map<string, multiset<string>> &routes, vector<string> &res, const string &current) {
    while(routes[current].size() > 0) {
        string next = *(routes[current].begin());
        routes[current].erase(routes[current].begin());
        dfs(routes, res, next);
    }
    res.push_back(current);
}

vector<string> findItinerary(vector<pair<string, string>> tickets) {
    vector<string> res;
    unordered_map<string, multiset<string>> routes;
    for(const auto &ticket : tickets) {
        routes[ticket.first].insert(ticket.second);
    }
    dfs(routes, res, "JFK");
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
