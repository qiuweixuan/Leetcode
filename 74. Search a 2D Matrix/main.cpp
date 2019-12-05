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
/*

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0){
            return false;
        }
        int col = matrix[0].size();
        if(col == 0){
            return false;
        }
        int n = row * col;

        int left = 0;
        int right = n;
        while(left < right){
            int mid = (left + right) / 2;
            int x = mid / col, y = mid % col;
            int midValue = matrix[x][y];
            if( midValue == target){
                return true;
            }
            else if(target <  midValue){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        return false;
    }
};
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0){
            return false;
        }
        int col = matrix[0].size();
        if(col == 0){
            return false;
        }


        int left = 0;
        int right = row;
        while(left < right){
            int mid = (left + right) / 2;
            int midValue = matrix[mid][col - 1];
            if( midValue == target){
                return true;
            }
            else if(target <  midValue){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        int curRow = right;
        if(curRow == row){
            return false;
        }

        left = 0,right = col;
        while(left < right){
            int mid = (left + right) / 2;
            int midValue = matrix[curRow][mid];
            if( midValue == target){
                return true;
            }
            else if(target <  midValue){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }


        return false;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}