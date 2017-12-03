//
//  main.cpp
//  179_LargestNumber
//
//  Created by Colin on 03/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool compareStrings(string s1, string s2) {
    string temp1 = s1 + s2, temp2 = s2 + s1;
    if(temp1 > temp2)
        return true;
    else
        return false;
}

string largestNumber(vector<int>& nums) {
    vector<string> numStr;
    for(const int num : nums) {
        numStr.push_back(to_string(num));
    }
    bool (*func)(string, string) = compareStrings;
    sort(numStr.begin(), numStr.end(), func);
    if(numStr[0] == "0")
        return "0";
    string res = "";
    for(const string & str : numStr) {
        res += str;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> nums = {3, 30, 34, 5, 9};
    cout << largestNumber(nums) << endl;
    return 0;
}
