//
//  main.cpp
//  252_Meeting Rooms
//
//  Created by Colin on 14/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include "../basic_ds.hpp"

using namespace std;

bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const Interval interval1, const Interval interval2) { return interval1.start < interval2.start; });
    int intervalCount = intervals.size();
    for(int i = 1; i < intervalCount; ++i) {
        if(intervals[i].start < intervals[i - 1].end)
            return false;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
