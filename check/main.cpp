//
//  main.cpp
//  check
//
//  Created by Colin on 23/03/2018.
//  Copyright © 2018 Colin. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main(){
    //freopen("1.in","r",stdin);
    int n;
    cin >> n;
    vector<pair<int, int>> record(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; ++j) {
            cin >> record[i].first;
        }
        for(int j = 0; j < 4; ++j) {
            cin >> record[i].second;
        }
        unordered_set<string> centerSet;
        pair<double, double> center;
        bool match = false;
        for(int ii = 0; ii < 4; ++ii) {
            for(int jj = ii; jj < 4; ++jj) {
                pair<double, double> current = {(record[ii].first + record[jj].first) * 1.0 / 2, (record[ii].second + record[jj].second) * 1.0/ 2};
                string currentStr = to_string(current.first) + "|" + to_string(current.second);
                if(centerSet.find(currentStr) != centerSet.end()) {
                    match = true;
                    center = current;
                } else {
                    centerSet.insert(currentStr);
                }
            }
        }
        if(match == false) {
            cout << "No" << endl;
            continue;
        }
        double distance = (center.first - record[0].first) * (center.first - record[0].first) + (center.second - record[0].second) * (center.second - record[0].second);
        cout << distance << endl;
        match = true;
        for(int j = 1; j < 4; ++j) {
            double current = (center.first - record[j].first) * (center.first - record[j].first) + (center.second - record[j].second) * (center.second - record[j].second);
            if(abs(current - distance) > 1e-5) {
                cout << j << endl;
                match = false;
                break;
            }
        }
        if(match == false) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
    
    return 0;
}

