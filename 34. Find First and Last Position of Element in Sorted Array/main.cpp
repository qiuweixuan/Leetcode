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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2,-1);
        if(nums.size() == 0){
            return ret;
        }

        //向左搜索和向右搜索是基本一致的
        //采用左闭右开区间

        int lo = 0,hi = nums.size();
        while(lo < hi){
            int mid = (lo + hi) / 2;

            //让右边不断靠近左边

            if(nums[mid] >= target){
                hi = mid;
            }
            else{
                lo = mid + 1;
            }
        }
        //注意边界问题，因为左边有可能在区域外，左边扫描到数组末尾
        //判断nums[lo] == target ?

        int left = lo < nums.size() && nums[lo] == target ? lo: -1;
        ret[0] = left;



        lo = 0,hi = nums.size();
        while(lo < hi){
            int mid = (lo + hi)/ 2;

            //让左边不断靠近右边

            if(nums[mid] <= target){
                lo = mid + 1;
            }
            else{
                hi = mid ;
            }
        }
        //注意边界问题，因为右边有可能在区域外，右边扫描到数组头
        //判断nums[hi - 1] == target ?

        int right = hi > 0 && nums[hi - 1] == target ? hi - 1: -1;
        ret[1] = right;


        return ret;
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}