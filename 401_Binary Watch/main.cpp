//
//  main.cpp
//  401_Binary Watch
//
//  Created by Colin on 24/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

void dfs(const vector<int> &array, vector<int> &result, int index, int remain, int currentSum) {
    if(remain == 0) {
        result.push_back(currentSum);
        return ;
    }
    int count = array.size();
    for(int i = index; i <= count - remain; ++i){
        dfs(array, result, i + 1, remain - 1, currentSum + array[i]);
    }
    return;
}

vector<string> readBinaryWatch(int num) {
    vector<string> res;
    if(num < 0 || num > 10)
        return res;
    const vector<int> hours = {8, 4, 2, 1};
    const vector<int> minutes = {32, 16, 8, 4, 2, 1};
    for(int i = 0; i <= num; ++i) {
        int j = num - i;
        if(i <= hours.size() && j <= minutes.size()) {
            vector<int> hourPart, minutePart;
            dfs(hours, hourPart, 0, i, 0);
            dfs(minutes, minutePart, 0, j, 0);
            for(const int hour : hourPart) {
                for(const int minute : minutePart) {
                    if(hour <= 11 && minute <= 59) {
                        string current = "";
                        current += to_string(hour) + ":";
                        if(minute < 10) {
                            current += "0";
                        }
                        current += to_string(minute);
                        res.push_back(current);
                    }
                }
            }
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<string> arr;
    arr = readBinaryWatch(1);
    for(auto ele : arr) {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}
