//
//  main.cpp
//  241_Different Ways to Add Parentheses
//
//  Created by Colin on 13/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int getNum(const string &str) {
    int value = 0;
    for(const char ch : str) {
        value = value * 10 + (ch - '0');
    }
    return value;
}

vector<int> diffWaysToCompute(string input) {
    vector<int> result;
    int inputLen = input.length();
    for(int i = 0; i < inputLen; ++i) {
        char currentChar = input[i];
        if(currentChar == '+' || currentChar == '-' || currentChar == '*') {
            vector<int> leftResult = diffWaysToCompute(input.substr(0, i));
            vector<int> rightResult = diffWaysToCompute(input.substr(i + 1));
            for(const int left : leftResult) {
                for(const int right : rightResult) {
                    if(currentChar == '+') {
                        result.push_back(left + right);
                    } else if(currentChar == '-') {
                        result.push_back(left - right);
                    } else {
                        result.push_back(left * right);
                    }
                }
            }
        }
    }
    if(result.size() == 0) {
        result.push_back(getNum(input));
    }
    return result;
}

int main(int argc, const char * argv[]) {
    auto res = diffWaysToCompute("2+8*9-2+1*7");
    for(int ele : res) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
