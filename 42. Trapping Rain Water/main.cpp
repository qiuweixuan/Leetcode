#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;
        int sumWater = 0;

        while(start < end){

            while(start < end && height[start] <= height[start + 1]){
                start++;
            }

            while(start < end && height[end - 1] >= height[end]){
                end--;
            }

            if(start >= end){
                break;
            }

            int curWater = 0;
            int minHeight = min(height[start],height[end]);


            if(height[start] <= height[end]){
                int mid;
                for (mid = start + 1; mid < end && height[mid] < minHeight; ++mid) {
                    curWater += minHeight - height[mid];
                }

                start = mid;
            }
            else{
                int mid;
                for (mid = end - 1; mid > start && height[mid] < minHeight; --mid) {
                    curWater += minHeight - height[mid];
                }
                end = mid;
            }
            sumWater += curWater;

        }

        return sumWater;
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
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().trap(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}