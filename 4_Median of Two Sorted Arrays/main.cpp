//
//  main.cpp
//  4_Median of Two Sorted Arrays
//
//  Created by Colin on 28/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int numCount1 = nums1.size(), numCount2 = nums2.size();
    vector<int> &n1 = numCount1 <= numCount2 ? nums1 : nums2;
    vector<int> &n2 = numCount1 <= numCount2 ? nums2 : nums1;
    if(numCount1 > numCount2) swap(numCount1, numCount2);
    bool isOdd = (numCount1 + numCount2) % 2;
    int imin = 0, imax = numCount1 - 1;
    int i = 0, j = 0;
    while(true) {
        i = imin + (imax - imin) / 2;
        j = numCount1 + (numCount2 - numCount1 + 1) / 2 - i;
        if((i == 0 || j == numCount2 || n1[i - 1] <= n2[j]) && (j == 0 || i == numCount1 || n2[j - 1] <= n1[i]))
            break;
        else if(i > 0 && j < numCount2 && n1[i - 1] > n2[j]) imax = i - 1;
        else if(j > 0 && i < numCount1 && n2[j - 1] > n1[i]) imin = i + 1;
    }
    double result = 0.0;
    int first = (i == 0 ? INT_MIN : n1[i - 1]);
    int second = (j == 0 ? INT_MIN : n2[j - 1]);
    if(isOdd) {
        result = max(first, second);
    } else {
        int third = (i == numCount1 ? INT_MAX : n1[i]);
        int fourth = (j == numCount2 ? INT_MAX : n2[j]);
        result = (max(first, second) + min(third, fourth)) / 2.0;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {1,2}, nums2 = {3,4};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
