//
//  main.cpp
//  264_Ugly Number II
//
//  Created by Colin on 05/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int nthUglyNumber(int n) {
    vector<int> record(n, 0);
    record[0] = 1;
    int index2 = 0, index3 = 0, index5 = 0;
    for(int i = 1; i < n; ++i) {
        record[i] = min(min(record[index2] * 2, record[index3] * 3), record[index5] * 5);
        if(record[i] == record[index2] * 2)
            ++index2;
        if(record[i] == record[index3] * 3)
            ++index3;
        if(record[i] == record[index5] * 5)
            ++index5;
    }
    return record[n - 1];
}

int main(int argc, const char * argv[]) {
    cout << nthUglyNumber(6) << endl;
    return 0;
}
