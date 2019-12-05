#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


/*

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDist = 1000000007;
        int closest;
        int len = nums.size();

        sort(nums.begin(),nums.end());


        for (int i = 0; i < len - 2 && minDist; ++i) {
            int lo = i + 1;
            int hi = len - 1;

            int sum = target - nums[i];

            while (lo < hi){
                int curSum = nums[lo] + nums[hi];
                int curDist = abs(sum - curSum);
                if(curDist < minDist){
                    minDist = curDist;
                    closest = curSum + nums[i];
                }


                if(nums[lo] + nums[hi] < sum){
                    lo++;
                }
                else if(nums[lo] + nums[hi] > sum){
                    hi--;
                }
                else{
                    break;
                }
            }
        }
        return closest;
    }
};

*/


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDist = 1000000007;
        int closest;
        int len = nums.size();

        sort(nums.begin(),nums.end());


        for (int i = 0; i < len - 2 && minDist; ++i) {
            for (int j = i + 1; j < len - 1 && minDist; ++j) {

                int curSum = nums[i] + nums[j];
                int kTarget = target - curSum;

                int lo = j + 1;
                int hi = len - 1;

                while(lo <= hi){
                    int mid = (lo + hi) / 2;

                    if(kTarget <= nums[lo]){   //case 3

                        int curDist = nums[lo] - kTarget;
                        if(curDist < minDist){
                            minDist = curDist;
                            closest = curSum + nums[lo];
                        }
                        break;

                    }
                    else if( kTarget >= nums[hi]){   //case 4

                        int curDist = kTarget - nums[hi];
                        if(curDist < minDist){
                            minDist = curDist;
                            closest = curSum + nums[hi];
                        }
                        break;

                    } else{ // nums[lo]< kTarget && kTarget < nums[hi]

                        int curDist = abs(nums[mid] - kTarget);
                        if(curDist < minDist){
                            minDist = curDist;
                            closest = curSum + nums[mid];
                        }

                        if(nums[mid] < kTarget){   //case 1
                            lo = mid + 1;
                        }
                        else if(nums[mid] >  kTarget){ //case 2
                            hi = mid - 1;
                        }
                        else{               // case 0
                            break;
                        }

                    }
                }
            }
        }
        return closest;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}