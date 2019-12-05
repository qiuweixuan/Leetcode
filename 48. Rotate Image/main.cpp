#include <iostream>


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
    void rotateRecur(vector<vector<int>>& matrix,int depth,int n){
        if(n == 0 || n == 1){
            return;
        }
        int minRow,minCol;
        minRow = minCol = depth;
        int maxRow,maxCol;
        maxRow = maxCol = depth + n - 1;

        for (int i = 0; i < n - 1; ++i) {
            int& num1 = matrix[minRow][minCol + i];
            int& num2 = matrix[minRow + i][maxCol];
            int& num3 = matrix[maxRow][maxCol - i];
            int& num4 = matrix[maxRow - i][minCol];

            swap(num1,num3);
            swap(num2,num3);
            swap(num1,num4);
        }
        rotateRecur(matrix,depth + 1,n - 2);

    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int depth = 0;
        rotateRecur(matrix,depth,n);
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}