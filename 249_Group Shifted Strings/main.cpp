//
//  main.cpp
//  249_Group Shifted Strings
//
//  Created by Colin on 25/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

vector<vector<string>> groupStrings(vector<string>& strings) {
    vector<vector<string>> res;
    unordered_map<string, int> record;
    for(const string &s : strings) {
        ++record[s];
    }
    while(!record.empty()) {
        auto current = record.begin();
        string base = current->first;
        vector<string> currentList;
        for(int i = 0; i < current->second; ++i) {
            currentList.push_back(base);
        }
        record.erase(base);
        for(int i = 1; i <= 25; ++i) {
            string temp = base;
            for(char &ch : temp) {
                ch = ((ch - 'a') + i) % 26 + 'a';
            }
            if(record.find(temp) != record.end()) {
                for(int j = 0; j < record[temp]; ++j) {
                    currentList.push_back(temp);
                }
                record.erase(temp);
            }
        }
        res.push_back(currentList);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
