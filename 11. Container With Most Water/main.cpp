#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

/*

class Solution {
public:
    static bool sortByHeight(pair<int,int>& p1,pair<int,int>& p2){
        return p1.second < p2.second;
    }


    int maxArea(vector<int>& height) {
//        pair<int,int> *list = new pair<int,int>[height.size()];

        int size = height.size();

        auto list = new pair<int,int>[size];
        for(int i = 0;i < size;i++){
            list[i].first = i;
            list[i].second = height[i];
        }

        sort(list,list + size,sortByHeight);

        int retArea = 0;
        for (int i = 0; i < size - 1; ++i) {
            int curWidth = 0;
            for (int j = i + 1; j < size; ++j) {
                curWidth = max(curWidth,abs(list[i].first - list[j].first));
            }

            int curArea = curWidth * list[i].second;
            retArea = max(retArea,curArea);
        }

        delete[](list);

        return retArea;
    }
};
*/

/*

class Solution {
public:

    int maxArea(vector<int>& height) {

        int size = height.size();

        int retArea = 0;
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                int curArea = (j - i) * min(height[i],height[j]);
                retArea = max(retArea,curArea);
            }
        }

        return retArea;
    }
};
*/



//o(n)算法，利用area = width * height,宽度越短，需要高度越高
//有可能更新最大面积，才进行比较更新

class Solution {
public:

    int maxArea(vector<int>& height) {

        int i = 0;
        int j = height.size() - 1;
        int water = 0;


        while (i < j){
            int h = min(height[i],height[j]);
            water = max(water,(j - i) * h);

            while (i < j && height[i] <= h){
                i++;
            }
            while (i < j && height[j] <= h){
                j--;
            }
        }

        return water;
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

        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}