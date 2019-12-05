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
    void solve(vector<vector<int>>& ret,vector<int>&com ,int start,int end,int k){
        if(k == 0){
            ret.push_back(com);
            return;
        }

        for (int i = start; i <= end - k + 1 ; ++i) {
            com.push_back(i);
            solve(ret,com,i + 1,end,k - 1);
            com.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if(n <= 0 || k <= 0){
            return ret;
        }

        vector<int> com;
        int start = 1,end = n;
        solve(ret,com,start,end,k);
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}