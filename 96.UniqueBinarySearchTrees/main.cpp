#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 0){
            return 0;
        }

        vector<vector<int> > dp(n + 2,vector<int>(n + 2,1));

        for (int dist = 1; dist <= n - 1 ; ++dist) {
            for (int left = 1; left <= n - dist; ++left) {
                int right = left + dist;
                dp[left][right] = 0;
                for (int mid = left; mid <= right; ++mid) {
                    dp[left][right] += dp[left][mid - 1] * dp[mid + 1][right];
                }
            }
        }

        return dp[1][n];
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}