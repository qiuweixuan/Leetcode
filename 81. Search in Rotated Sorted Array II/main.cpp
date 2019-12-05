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
    bool solve(vector<int>& nums, int target,int left, int right){


        while (left < right){
            int middle = (left + right) / 2;
            if(nums[middle] == target){
                return true;
            }

            if(nums[left] ==  nums[middle] == nums[right - 1]){
                return   solve(nums,target,left + 1,middle) || solve(nums,target,middle + 1,right) ;
            }
            else if(nums[left] <= nums[middle]){
                if( nums[left] <= target && target < nums[middle]){
                    right = middle;
                }
                else{
                    left = middle + 1;
                }
            }
            else{
                if( nums[middle] < target && target <= nums[right - 1]){
                    left = middle + 1;
                }
                else{
                    right = middle;
                }
            }

        }


        return false;
    }
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();

        //return solve(nums,target,left,right);
        while (left < right){
            int middle = (left + right) / 2;
            if(nums[middle] == target){
                return true;
            }

            if(nums[left] ==  nums[middle] == nums[right - 1]){
                for (int i = left; i < right; ++i) {
                    if(nums[i] == target){
                        return true;
                    }
                }
                return false;
            }
            else if(nums[left] <= nums[middle]){
                if( nums[left] <= target && target < nums[middle]){
                    right = middle;
                }
                else{
                    left = middle + 1;
                }
            }
            else{
                if( nums[middle] < target && target <= nums[right - 1]){
                    left = middle + 1;
                }
                else{
                    right = middle;
                }
            }

        }


        return false;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}