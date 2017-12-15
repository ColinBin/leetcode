//
//  main.cpp
//  253_Meeting Rooms II
//
//  Created by Colin on 14/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"
#include <vector>

using namespace std;

int minMeetingRooms(vector<Interval>& intervals) {
    vector<int> start;
    vector<int> finish;
    for(const auto &interval : intervals) {
        start.push_back(interval.start);
        finish.push_back(interval.end);
    }
    sort(start.begin(), start.end());
    sort(finish.begin(), finish.end());
    int finishIndex = 0;
    int room = 0;
    for(int i = 0; i < intervals.size(); ++i) {
        if(start[i] < finish[finishIndex]) {
            ++room;
        } else {
            ++finishIndex;
        }
    }
    return room;
}

int main(int argc, const char * argv[]) {

    return 0;
}
