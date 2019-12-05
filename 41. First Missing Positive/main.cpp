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
/*

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int minValue =  1000000007;
        int maxValue = -1000000007;

        int sum = 0;
        for(int value : nums){
            sum += value;
            minValue = min(value,minValue);
            maxValue = max(value,maxValue);
        }


        int missValue;
        if(minValue + nums.size() - 1 == maxValue){
            missValue = maxValue + 1;
        } else{
            int expectedSum = (minValue + maxValue - 1) * nums.size() / 2;
            missValue = maxValue - (sum - expectedSum);
        }
        return missValue;
    }
};
*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            //是一个正数，且另一个数不应该在那个位置上
            //则把这个数放到对应的位置上
            //不断交换，直至某个位置上的结果正确为止  nums[(nums[i] - 1)] == nums[i]
            // 或者找不到相应的元素 ，即nums[i] > 0 && nums[i] - 1 < nums.size() == false


            while(nums[i] > 0 && nums[i] - 1 < nums.size() && nums[(nums[i] - 1)] != nums[i] ){
                swap(nums[i],nums[(nums[i] - 1)]);
            }

        }



        int missIndex = 1;
        //在对应位置是否有对应值，有则检查下一个位置，没有则是位置
        //巧妙运用标记位（bool数组思想）

        for (int i = 0; i < nums.size() && nums[i] == i + 1; ++i) {
            missIndex++;
        }

        return missIndex;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        int ret = Solution().firstMissingPositive(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}