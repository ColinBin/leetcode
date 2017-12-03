//
//  main.cpp
//  37_sudoku_solver
//
//  Created by Colin on 06/11/2017.
//  Copyright © 2017 Colin. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(vector<vector<char>> &board, int curr_i, int curr_j, int value) {
    char chVal = value + '0';
    for(int k = 0; k < 9; ++k) {
        int small_i = curr_i / 3 * 3 + k / 3, small_j = curr_j / 3 * 3 + k % 3;
        if(board[curr_i][k] == chVal || board[k][curr_j] == chVal || board[small_i][small_j] == chVal) {
            return false;
        }
    }
    return true;
}

void findNext(vector<vector<char>> &board, int curr_i, int curr_j, int &next_i, int &next_j) {
    for(int i = curr_i; i < 9; ++i) {
        for(int j = ((i == curr_i) ? curr_j + 1 : 0); j < 9; ++j) {
            if(board[i][j] == '.') {
                next_i = i;
                next_j = j;
                return;
            }
        }
    }
    next_i = next_j = -1;
    return ;
}

bool solve(vector<vector<char>> &board, int curr_i, int curr_j) {
    int next_i = -2, next_j = -2;
    findNext(board, curr_i, curr_j, next_i, next_j);
    for(int choice = 1; choice <= 9; ++choice) {
        if(isValid(board, curr_i, curr_j, choice)) {
            board[curr_i][curr_j] = '0' + choice;
            // current is the last position to fill, done
            if(next_i == -1) {
                return true;
            }
            // work to do
            // successful when solving subproblem
            if(solve(board, next_i, next_j)) {
                return true;
            } else {
                // cannot work out
                board[curr_i][curr_j] = '.';
            }
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    for(int i = 0; i < 9; ++i) {
        for(int j = 0; j < 9; ++j) {
            if(board[i][j] == '.') {
                solve(board, i, j);
                break;
            }
        }
    }
}

int main(int argc, const char * arg[]) {
    vector<vector<char>> board = {{'.','.','9','7','4','8','.','.','.'},{'7','.','.','.','.','.','.','.','.'},{'.','2','.','1','.','9','.','.','.'},{'.','.','7','.','.','.','2','4','.'},{'.','6','4','.','1','.','5','9','.'},{'.','9','8','.','.','.','3','.','.'},{'.','.','.','8','.','3','.','2','.'},{'.','.','.','.','.','.','.','.','6'},{'.','.','.','2','7','5','9','.','.'}};
    solveSudoku(board);
    for(auto row : board) {
        for(auto ele : row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}

