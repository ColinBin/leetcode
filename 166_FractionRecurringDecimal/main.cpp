//
//  main.cpp
//  166_FractionRecurringDecimal
//
//  Created by Colin on 02/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0)
        return "0";
    string res = "";
    long num = labs(numerator), den = labs(denominator);
    if((num > 0) ^ (den > 0))
        res += "-";
    res += to_string(num / den);
    long remainder = num % den;
    if(remainder == 0)
        return res;
    res += ".";
    unordered_map<int, int> track;
    while(remainder != 0) {
        if(track.find(remainder) != track.end()) {
            res.insert(track[remainder], "(");
            res += ")";
            return res;
        }
        track[remainder] = res.length();
        remainder *= 10;
        res += to_string(remainder / den);
        remainder = remainder % den;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    cout << fractionToDecimal(1,6) << endl;
    return 0;
}
