//
//  main.cpp
//  419Battleships in a Board
//
//  Created by Colin on 09/12/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int countBattleships(vector<vector<char>>& board) {
    int rowCount = board.size();
    if(rowCount == 0)
        return 0;
    int colCount = board[0].size();
    int count = 0;
    for(int i = 0; i < rowCount; ++i) {
        for(int j = 0; j < colCount; ++j) {
            if(board[i][j] == '.')
                continue;
            if(i > 0 && board[i - 1][j] == 'X')
                continue;
            if(j > 0 && board[i][j - 1] == 'X')
                continue;
            ++count;
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    
    return 0;
}
