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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int> >dp(n + 1,vector<int>(m + 1,0));

        //从一个非空字符串变为一个空字符，做length个删除操作

        for (int i = 1; i <= n; ++i) {
            dp[i][0] = i;
        }
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m ; ++j) {
                //当前字符匹配，无需进行编辑操作

                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                } else{
                    //如果字符不相等，则说明需要编辑
                    //三种编辑操作：替换，添加j，删除i

                    dp[i][j] = min(dp[i - 1][j - 1],min(dp[i][j - 1],dp[i - 1][j])) + 1;
                }
            }
        }

        return dp[n][m];
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}