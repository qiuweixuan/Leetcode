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

/*
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int> >jumpRow(row,vector<int>(col,-1));
        for (int i = 0; i < row; ++i) {
            int left = 0;
            while (left < col){
                int right = left + 1;
                while (right < col && matrix[i][left] == matrix[i][right]){
                    right++;
                }
                while(left < right){
                    jumpRow[i][left] = right;
                    left++;
                }
            }
        }

        vector<vector<int> > jumpCol(row,vector<int>(col,-1));
        for (int i = 0; i < col; ++i) {
            int left = 0;
            while (left < row){
                int right = left + 1;
                while (right < row && matrix[left][i] == matrix[right][i]){
                    right++;
                }
                while(left < right){
                    jumpCol[left][i] = right;
                    left++;
                }
            }
        }


        //vector<vector<bool> > isUsed(row,vector<bool>(col,false));

        int maxArea = 0;
        for (int i = 0; i < row; ++i) {
           int left = 0;
           while (left < col){
               while (left < col && matrix[i][left] == '0' ){
                   //cout<<"!"<<i<< " " <<left<<" "<<jumpRow[i][left]<<endl;
                   left = jumpRow[i][left];
               }

               if(left == col){
                   break;
               }

               //cout<<i<< " " <<left<<" "<<right<<endl;

              for (int j = i,height = 1,width = 1000000007 ; j < jumpCol[i][left]; ++j,++height) {
                   width = min(width,jumpRow[j][left] - left);
                   int curArea = width * height;
                   maxArea = max(maxArea,curArea);
               }
               left++;
           }
        }
        return maxArea;
    }
};
*/


class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()){
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> matrixOneLeft(col , -1 );
        vector<int> matrixOneRight(col , col + 1);
        vector<int> matrixOneHight(col,0);
        int maxArea = 0;
        for (int i = 0; i < row; ++i) {
            int curLeft = 0,curRight = col;
            for (int j = 0; j < col; ++j) {
                if(matrix[i][j] == '0'){
                    curLeft = j + 1;
                    matrixOneLeft[j] = -1;
                } else{
                    matrixOneLeft[j] = max(matrixOneLeft[j],curLeft);
                }
            }

            for (int j = col - 1; j >= 0 ; --j) {
                if(matrix[i][j] == '0' ){
                    curRight = j;
                    matrixOneRight[j] =  col + 1;
                } else{
                    matrixOneRight[j] = min(matrixOneRight[j],curRight);
                }
            }

            for (int j = 0; j < col; ++j) {
                if(matrix[i][j] == '0'){
                    matrixOneHight[j] = 0;
                }
                else{
                    matrixOneHight[j]++;
                }
            }

            for (int j = 0; j < col; ++j) {
                int curArea = (matrixOneRight[j] - matrixOneLeft[j]) * matrixOneHight[j];
                maxArea = max(maxArea,curArea);
            }

        }

        return maxArea;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}