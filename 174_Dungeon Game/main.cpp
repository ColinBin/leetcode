//
//  main.cpp
//  174_Dungeon Game
//
//  Created by Colin on 22/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include "../basic_ds.hpp"

using namespace std;

int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int rowCount = dungeon.size();
    if(rowCount == 0)
        return -1;
    int colCount = dungeon[0].size();
    vector<int> hp(colCount + 1, INT_MAX);
    hp[colCount - 1] = 1;
    for(int i = rowCount - 1; i >= 0; --i) {
        for(int j = colCount - 1; j >= 0; --j) {
            int need = min(hp[j + 1], hp[j]) - dungeon[i][j];
            hp[j] = need <= 0 ? 1 : need;
        }
    }
    return hp[0];
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> dungeon = {{1,-4,5,-99},{2,-2,-2,-1}};
    cout << calculateMinimumHP(dungeon) << endl;
    return 0;
}
