//
//  main.cpp
//  294_Flip Game II
//
//  Created by Colin on 08/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool canWinHelper(string &s, unordered_map<string, bool> &record) {
    int sLen = s.length();
    if(sLen < 2) {
        return false;
    }
    for(int i = 0; i < sLen - 1; ++i) {
        if(s[i] == '+' && s[i + 1] == '+') {
            s[i] = '-';
            s[i + 1]  = '-';
            
            bool res = false;
            if(record.find(s) != record.end()) {
                res = record[s];
            } else {
                res = canWinHelper(s, record);
                record[s] = res;
            }
            
            s[i] = '+';
            s[i + 1] = '+';
            
            if(!res)
                return true;
        }
    }
    record[s] = false;
    return false;
}

bool canWin(string s) {
    // backtracing
    unordered_map<string, bool> record;
    return canWinHelper(s, record);
}


int main(int argc, const char * argv[]) {
    cout << canWin("++++-+---++") << endl;
    return 0;
}
