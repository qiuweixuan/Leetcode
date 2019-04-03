#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dpMatrixMulti(vector<int>& values){
    int size = values.size();
    vector<vector<int>> dp(size,vector<int>(size,0));
    //i < k < j
    for (int len = 1; len <= size - 2 ; ++len) {
        for (int i = 0; i <= size - 2 - len; ++i) {
            int j = i + len + 1;
            for (int k = i + 1; k <= j - 1; ++k) {
                dp[i][j] = max(dp[i][j],dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
            }
        }
    }

    return dp[0][size - 1];
}


int main() {
    int v;
    vector<int> values;
    values.push_back(1);
    while (cin>>v){
        values.push_back(v);
    }
    values.push_back(1);
    cout<<dpMatrixMulti(values)<<endl;
    return 0;
}
//3 5 1 8