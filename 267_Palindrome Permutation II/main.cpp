//
//  main.cpp
//  267_Palindrome Permutation II
//
//  Created by Colin on 15/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

void permutate(vector<string> &res, string &half, string &mid, int index) {
    if(index == half.length()) {
        string theOtherHalf = half;
        reverse(theOtherHalf.begin(), theOtherHalf.end());
        res.push_back(half + mid + theOtherHalf);
        return;
    }
    set<char> checked;
    for(int i = index; i < half.length(); ++i) {
        if(checked.find(half[i]) == checked.end()) {
            checked.insert(half[i]);
            swap(half[i], half[index]);
            permutate(res, half, mid, index + 1);
            swap(half[i], half[index]);
        }
    }
    return ;
}

vector<string> generatePalindromes(string s) {
    vector<string> res;
    unordered_map<char, int> record;
    for(const char ch : s) {
        ++record[ch];
    }
    int oddCount = 0;
    string half = "";
    string mid = "";
    for(const auto &ele : record) {
        if(ele.second & 0x01) {
            ++oddCount;
            if(oddCount == 2) {
                return res;
            }
            mid = ele.first;
            // aaa
            if(ele.second > 1) {
                half += string(ele.second / 2, ele.first);
            }
        } else {
            half += string(ele.second / 2, ele.first);
        }
    }
    permutate(res, half, mid, 0);
    return res;
}

int main(int argc, const char * argv[]) {
    generatePalindromes("abcab");
    return 0;
}
