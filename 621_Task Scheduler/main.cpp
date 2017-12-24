//
//  main.cpp
//  621_Task Scheduler
//
//  Created by Colin on 23/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    vector<int> record(26, 0);
    for(const char ch : tasks) {
        ++record[ch - 'A'];
    }
    sort(record.begin(), record.end());
    int maxVal = record[25] - 1, idle = maxVal * n;
    for(int i = 24; i >= 0 && record[i] > 0; --i) {
        idle -= min(maxVal, record[i]);
    }
    return idle > 0 ? idle + tasks.size() : tasks.size();
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
