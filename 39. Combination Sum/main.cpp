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

    void searchZero(vector<vector<int>>& ret,vector<int>& candidates,vector<int>& curCandi, int target,int id){
        if(target == 0){
            ret.push_back(curCandi);
            return; //true
        }
        if(id == candidates.size()){
            return; //false
        }

        int value = candidates[id];
        int prevLen = curCandi.size();

        for (int i = 0; i  * value <= target; ++i) {
            searchZero(ret,candidates,curCandi, target - i * value,id + 1);
            curCandi.push_back(value);
        }
        curCandi.resize(prevLen);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curCandi;
        int id = 0;
        searchZero(ret,candidates,curCandi,target,id);

        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}