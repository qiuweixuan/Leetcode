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
    bool canJump(vector<int>& nums) {

        if(nums.empty()){
            return false;
        }
        int targetNode = nums.size() - 1;

        int maxJumpNode = 0;
        int leftNode = 0;
        int rightNode = 1;

        while (leftNode < rightNode && maxJumpNode < targetNode){

            for (int i = leftNode; i < rightNode ; ++i) {
                maxJumpNode = max(i + nums[i],maxJumpNode);
            }
            leftNode = rightNode;
            rightNode = maxJumpNode + 1;
        }

        if(maxJumpNode >= targetNode){
            return  true;
        } else{
            return false;
        }
    }
};
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {

        if(nums.empty()){
            return false;
        }
        int targetNode = nums.size() - 1;
        int maxJumpNode = 0;
        for (int i = 0; i < nums.size() && i <= maxJumpNode; ++i) {
            maxJumpNode = max(i + nums[i],maxJumpNode);
        }

        return maxJumpNode >= targetNode;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().canJump(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}