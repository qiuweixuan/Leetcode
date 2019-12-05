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

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.empty()){
            ret.push_back(vector<int>());
            return ret;
        }

        map<int,int> counts;
        for (int v : nums){
            counts[v]++;
        }
        vector<int> subset;
        recur(counts,counts.begin(),ret,subset);

        return ret;
    }
private:
    void recur(map<int,int>&counts,map<int,int>::iterator it,vector<vector<int>>& ret,vector<int>& subset){
        if(it == counts.end()){
            ret.push_back(subset);
            return;
        }
        int elem = it->first;
        int size = it->second;
        it++;
        recur(counts,it,ret,subset);
        for (int i = 0; i < size; ++i) {
            subset.push_back(elem);
            recur(counts,it,ret,subset);
        }
        for (int i = 0; i < size; ++i) {
            subset.pop_back();
        }
    }
};

int main() {
    int n;
    while (cin>>n){
        vector<int> input(n);
        for (int i = 0; i < n; ++i) {
            cin>>input[i];
        }
        auto lists = Solution().subsetsWithDup(input);
        for(auto list : lists){
            for(auto v : list){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}