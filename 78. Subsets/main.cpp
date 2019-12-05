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
    void solve(vector<vector<int>>& ret,vector<int>& subset,vector<int>& nums,int n){
        if(n == nums.size()){
            ret.push_back(subset);
            return;
        }

        solve(ret,subset,nums,n + 1);
        subset.push_back(nums[n]);
        solve(ret,subset,nums,n + 1);
        subset.pop_back();
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> subset;
        solve(ret,subset,nums,0);

        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}