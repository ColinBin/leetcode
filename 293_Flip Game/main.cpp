//
//  main.cpp
//  293_Flip Game
//
//  Created by Colin on 08/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> generatePossibleNextMoves(string s) {
    vector<string> res;
    for(int i = 0; i < s.length() - 1; ++i) {
        if(s[i] == '+' && s[i + 1] == '+') {
            s[i] = s[i + 1] = '-';
            res.push_back(s);
            s[i] = s[i + 1] = '+';
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    string s = "++--++--+-+";
    auto res = generatePossibleNextMoves(s);
    for(string & ele : res) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
