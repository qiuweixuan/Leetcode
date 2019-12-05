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
/*

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dist(size,-1);
        dist[0] = 0;

        queue<int> que[2];
        que[0].push(0);
        int curQueID = 0;
        int nextQueID = 1;

        while (dist[size - 1] == -1){
            while (!que[curQueID].empty()){
                int id = que[curQueID].front();
                que[curQueID].pop();

                for (int skip = 1; skip <= nums[id] && id + skip < size ; ++skip) {
                    int next = id + skip;
                    if(dist[next] == -1){
                        dist[next] = dist[id] + 1;
                        que[nextQueID].push(next);
                    }
                }
                if(dist[size - 1] != -1){
                    return dist[size - 1];
                }
            }
            swap(curQueID,nextQueID);


        }

        return dist[size - 1];
    }
};

*/

/*

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dist(size,-1);

        //起点

        dist[0] = 0;

        //左闭右开区间

        int leftNode = 0 + 1;
        int rightNode = nums[0] + 1;

        while (dist[size - 1] == -1){
            int maxJump = 0;

            for (int i = leftNode; i < rightNode && i < size; ++i) {
                dist[i] = dist[leftNode - 1] + 1;
                int curJump = i + nums[i];
                maxJump = max(maxJump,curJump);
            }

            leftNode = rightNode;
            rightNode = maxJump + 1;
        }

        return dist[size - 1];
    }
};
*/

/*

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();

        //特殊情况处理

        if(nums.size() == 1){
            return 0;
        }

        //跳跃数

        int step = 0;

        //默认起点[0,1) 运算起点[leftNode，rightNode + 1)
        //左闭右开区间

        int leftNode = 0 + 1;
        int rightNode = nums[0] + 1;

        //不断进行跳跃

        while (leftNode < size ){
            step++;
            int maxJump = 0;
            for (int i = leftNode; i < rightNode && i < size; ++i) {
                int curJump = i + nums[i];
                maxJump = max(maxJump,curJump);
            }
            leftNode = rightNode;
            rightNode = maxJump + 1;
        }

        return step;
    }
};
*/


class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }

        int step = 1;

        int maxJumpNode  = nums[0];
        int targetNode =  nums.size() - 1;


        int i = 0;
        while (maxJumpNode < targetNode ){
            int prevMaxNode = maxJumpNode;
            while (i <= prevMaxNode){
                maxJumpNode = max(i + nums[i],maxJumpNode);
                i++;
            }
            step++;
        }

        return step;
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

        int ret = Solution().jump(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}