//
//  main.cpp
//  247_Strobogrammatic Number II
//
//  Created by Colin on 18/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, char> dict = {
    {'1', '1'}, {'0', '0'}, {'8', '8'}, {'6', '9'}, {'9', '6'}
};
vector<string> special = {"1", "8", "0"};
vector<string> empty = {""};

void dfs(vector<string> &res, int index, const int total, string temp, const vector<string> &mid) {
    if(index == total) {
        string theOther = "";
        for(int i = temp.length() - 1; i >= 0; --i) {
            theOther += dict[temp[i]];
        }
        for(const string &currentMid : mid) {
            res.push_back(temp + currentMid + theOther);
        }
        return ;
    }
    for(const auto &ele : dict) {
        if(index == 0 && ele.first == 0)
            continue;
        dfs(res, index + 1, total, temp + ele.first, mid);
    }
    return;
}

vector<string> findStrobogrammatic(int n) {
    vector<string> res;
    if(n % 2 == 1) {
        dfs(res, 0, n / 2, "", special);
    } else {
        dfs(res, 0, n / 2, "", empty);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    return 0;
}
