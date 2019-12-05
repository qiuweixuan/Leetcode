#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <stack>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
     bool usedRows[9][9],usedCols[9][9],usedBlocks[9][9];

    bool fillSudoku(vector<vector<char>>& board,int curID){
        if(curID == 81){
            return true;
        }
        int row = curID / 9 ;
        int col = curID % 9;
        int block = (row / 3) * 3  + (col / 3);

        if(board[row][col] != '.'){
            return fillSudoku(board,curID + 1);
        }
        else{
            for (int num = 0; num < 9; ++num) {
                if(usedRows[row][num] || usedCols[col][num] || usedBlocks[block][num]){
                    continue;
                }
                usedRows[row][num] = usedCols[col][num] = usedBlocks[block][num] = true;
                board[row][col] = '1' + num;
                bool isVaild = fillSudoku(board,curID + 1);
                if(isVaild){
                    return true;
                }
                else{
                    board[row][col] = '.';
                    usedRows[row][num] = usedCols[col][num] = usedBlocks[block][num] = false;
                }
            }
            return false;
        }

    }
    void solveSudoku(vector<vector<char>>& board) {


        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                usedRows[i][j] = usedCols[i][j] = usedBlocks[i][j] = false;
            }
        }

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if(c == '.'){
                    continue;
                }
                int num = c - '1';
                int k = (i / 3) * 3  + (j / 3);
                usedRows[i][num] = usedCols[j][num] = usedBlocks[k][num] = true;
            }
        }

        fillSudoku(board,0);

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}