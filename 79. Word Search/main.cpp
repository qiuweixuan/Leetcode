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
#include <queue>
using namespace std;
class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word,vector<vector<bool>>& isUsed,int len,int x,int y){
        int rows = board.size();
        int cols = board[0].size();

        if(len == word.size()){
            return true;
        }
        if( x < 0 || x >= rows || y < 0 || y >= cols){
            return false;
        }
        if(isUsed[x][y] || word[len] != board[x][y]){
            return false;
        }
        isUsed[x][y] = true;

        bool ret = solve(board,word,isUsed,len + 1,x - 1,y) ||
                solve(board,word,isUsed,len + 1,x + 1,y) ||
                solve(board,word,isUsed,len + 1,x ,y - 1) ||
                solve(board,word,isUsed,len + 1,x ,y + 1);
        isUsed[x][y] = false;
        return ret;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || word.empty()){
            return false;
        }

        int wordLen = word.size();
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> isUsed(rows,vector<bool>(cols,false));
        //queue<pair<int,int> > que;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if(board[i][j] != word[0]){
                    continue;
                } else{
                    bool ret = solve(board,word,isUsed,0,i,j);
                    if(ret){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};


int main() {
    vector<string> board1 = {"ABCE","SFCS","ADEE"};
    vector<vector<char>> board2;
    for (int i = 0; i < board1.size(); ++i) {
        vector<char> t(board1[i].begin(),board1[i].end());
        board2.push_back(t);
    }
    string word = "ABCCED";
    Solution().exist(board2,word);


    return 0;
}