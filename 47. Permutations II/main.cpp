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

    void getNext(vector<vector<int>>& ret,vector<int>& nums,int usedSize){
        if(usedSize == nums.size()){
            ret.push_back(nums);
            return;
        }
        getNext(ret,nums,usedSize + 1);

        for (int i = usedSize + 1; i < nums.size(); ++i) {
            if(nums[usedSize] == nums[i]){
                continue;
            }
            swap(nums[usedSize],nums[i]);
            getNext(ret,nums,usedSize + 1);

        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        getNext(ret,nums,0);

        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}