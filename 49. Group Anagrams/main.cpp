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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string> > groups;
        for(string str : strs){
            string sortStr = str;
            sort(sortStr.begin(),sortStr.end());
            groups[sortStr].push_back(str);
        }

        vector<vector<string>> ret;
        for(auto group : groups){
            auto valueList = group.second;
            ret.push_back(valueList);
        }

        return ret;
    }
};


int main() {
    vector<string> list = {"ate","eat","tea"};
    Solution().groupAnagrams(list);

    return 0;
}