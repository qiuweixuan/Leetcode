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
    bool isValidSudoku(vector<vector<char>>& board) {
        bool usedRows[9][9],usedCols[9][9],usedBlocks[9][9];
        bool isValid = true;

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
                if(usedRows[i][num] || usedCols[j][num] || usedBlocks[k][num]){
                    isValid = false;
                    break;
                }
                usedRows[i][num] = usedCols[j][num] = usedBlocks[k][num] = true;
            }
        }

        return isValid;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}