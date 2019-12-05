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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[100][100];

        int m = obstacleGrid.size();
        if(m == 0){
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n == 0){
            return 0;
        }

        for (int i = 0; i <  m ; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = 0;
            }
        }

        for (int i = 0; i < m && obstacleGrid[i][0] != 1; ++i) {
            dp[i][0] = 1;
        }

        for (int j = 0; j < n && obstacleGrid[0][j] != 1; ++j) {
            dp[0][j] = 1;
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] != 1)
                {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
                }

            }
        }

        return dp[m - 1][n - 1];
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}