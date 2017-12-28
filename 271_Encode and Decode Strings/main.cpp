//
//  main.cpp
//  271_Encode and Decode Strings
//
//  Created by Colin on 27/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for(const string &str : strs) {
            res += to_string(str.length()) + ":";
            res += str;
        }
        return res;
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int i = 0;
        int sLen = s.length();
        vector<string> res;
        while(i != sLen) {
            int currentPos = s.find_first_of(':', i);
            int strLen = stoi(s.substr(i, currentPos - i));
            res.push_back(s.substr(currentPos + 1, strLen));
            i = currentPos + 1 + strLen;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string s = "fafcc";
    cout << s.find_first_of('c', 2) << endl;
    return 0;
}
