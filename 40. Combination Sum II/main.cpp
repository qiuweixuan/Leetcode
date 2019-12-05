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

//class Solution {
//public:
//
//    void searchZero(set<vector<int>>& ret,vector<int>& candidates,vector<int>& curCandi, int target,int id){
//        if(target == 0){
//            ret.insert(curCandi);
//            return; //true
//        }
//        if(id == candidates.size()){
//            return; //false
//        }
//
//        int value = candidates[id];
//
//        if(value <= target){
//            searchZero(ret,candidates,curCandi, target,id + 1);
//            curCandi.push_back(value);
//            searchZero(ret,candidates,curCandi, target -  value,id + 1);
//            curCandi.pop_back();
//        }
//
//    }
//
//    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//        set<vector<int>> retSet;
//        vector<int> curCandi;
//
//       /* 通过排序
//        * （1）能生成有序的组合（即将组合变为排列），这样set添加元素时不会有实质上重复的组合
//        * （2）能及时实现剪枝，当目标已不可能实现时（当前部分和大于目标值），可以正确剪枝
//        */
//        sort(candidates.begin(),candidates.end());
//        int id = 0;
//        searchZero(retSet,candidates,curCandi,target,id);
//
//        vector<vector<int>> retVector;
//        for(vector<int> v : retSet){
//            retVector.push_back(v);
//        }
//
//
//        return retVector;
//    }
//};

class Solution {
public:

    void searchZero(vector<vector<int>>& ret,map<int,int>& candiCount,vector<int>& curCandi, int target,map<int,int>::iterator it){
        //找到结果

        if(target == 0){
            ret.push_back(curCandi);
            return; //true
        }
        //遍历完所有元素

        if(it == candiCount.end()){
            return; //false
        }

        int value = it->first;
        int count = it->second;
        int prevLen = curCandi.size();
        ++it;

        //在此处实现剪枝，即i  * value <= target


        for (int i = 0; i  * value <= target && i <= count; ++i) {
            searchZero(ret,candiCount,curCandi, target - i * value,it);
            curCandi.push_back(value);
        }
        curCandi.resize(prevLen);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curCandi;
        int id = 0;

        //sort(candidates.begin(),candidates.end());
        //unordered_map<int,int> candiCount;

        //哈希表无序，不方便实现剪枝。红黑树是二叉搜索树，遍历有序，可以实现剪枝

        map<int,int> candiCount;
        for(int value : candidates){
            if(value <= target){
                candiCount[value]++;
            }
        }
        auto it = candiCount.begin();

        searchZero(ret,candiCount,curCandi,target,it);

        return ret;
    }
};


/*
class Solution {
public:

    void searchZero(vector<vector<int>>& ret, unordered_map<int,int>& candiCount,vector<int>& curCandi, int target,unordered_map<int,int>::iterator it){
        //找到结果

        if(target == 0){
            ret.push_back(curCandi);
            return; //true
        }
        //遍历完所有元素

        if(it == candiCount.end()){
            return; //false
        }

        int value = it->first;
        int count = it->second;
        int prevLen = curCandi.size();
        ++it;

        //在此处实现剪枝，即i  * value <= target


        for (int i = 0; i  * value <= target && i <= count; ++i) {
            searchZero(ret,candiCount,curCandi, target - i * value,it);
            curCandi.push_back(value);
        }
        curCandi.resize(prevLen);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> curCandi;
        int id = 0;

        //sort(candidates.begin(),candidates.end());
        unordered_map<int,int> candiCount;

        //哈希表无序，不方便实现剪枝。红黑树是二叉搜索树，遍历有序，可以实现剪枝

        //map<int,int> candiCount;
        for(int value : candidates){
            if(value <= target){
                candiCount[value]++;
            }
        }
        auto it = candiCount.begin();

        searchZero(ret,candiCount,curCandi,target,it);

        return ret;
    }
};
*/

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}