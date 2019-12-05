#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        map<int,int> value2index;

        for (int i = 0; i < nums.size(); ++i) {
            value2index[nums[i]] = i;
        }

        int left = 0;
        int right = nums.size() - 1;
        vector<vector<int>> ret;


        while (right - left >= 2 && nums[right] >= 0){


            while(right - left >= 2 && nums[left] + nums[right - 1] + nums[right] < 0){
                left++;
            }

            int a = left;
            int b = right - 1;
            int c = right;

            while(a <= b){

            }









        }



    }
};




int main() {

    return 0;
}



