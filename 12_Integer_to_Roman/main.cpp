//
//  main.cpp
//  12_Integer_to_Roman
//
//  Created by Colin on 15/10/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

string intToRoman(int num) {
    map<int, string> record = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"}
    };
    string res;
    for(auto iter = record.rbegin(), end = record.rend(); iter != end; ++iter) {
        while(num >= iter->first) {
            res += iter->second;
            num -= iter->first;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout << intToRoman(435) << endl;
    return 0;
}
