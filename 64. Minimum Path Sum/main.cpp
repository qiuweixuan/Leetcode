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
    int minPathSum(vector<vector<int>>& grid) {
        int sum = 0;
        int n = grid.size();
        if(n == 0){
            return sum;
        }
        int m = grid[0].size();
        if(m == 0){
            return sum;
        }


        vector<vector<int>> path;
        for (int i = 0; i < n; ++i) {
            path.push_back(vector<int>(m));
        }

        path[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            path[0][i] = path[0][i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; ++i) {
            path[i][0] = path[i - 1][0] + grid[i][0];
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                path[i][j] = min(path[i - 1][j],path[i][j - 1]) + grid[i][j];
            }
        }

        return path[n - 1][m - 1];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}