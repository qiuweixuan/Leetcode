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
const int INF = 1000000007;

class Solution {
public:
    int solve(vector<vector<int> > graph){
        int row  = graph.size();
        int col = graph[0].size();

        vector<vector<int> > minJump(row,vector<int>(col,INF));
        for (int i = 0; i < col; ++i) {
            minJump[0][i] = 0;
        }

        for (int j = 0; j < col - 1; ++j) {
            for ( int i = 0; i < row; ++i) {
                int dist = graph[i][j];
                int left = j + 1;
                int right = j + dist;
                int curJump = minJump[i][j] + 1;
                for (int k = j + 1; k <= right && k < col ; ++k) {
                    if( curJump < minJump[i][k] ){
                        minJump[i][k] = curJump;
                        int dist2 = graph[i][k];
                        int low = i - dist;
                        int high = i + dist;

                        for (int lo = i - 1; lo >= low && lo >= 0; --lo) {
                            if(curJump + 1 < minJump[lo][k]){
                                minJump[lo][k] = curJump + 1;
                            }
                        }

                        for (int hi = i + 1; hi <= high &&  hi < col; hi++) {
                            if(curJump + 1 < minJump[hi][k]){
                                minJump[hi][k] = curJump + 1;
                            }
                        }
                    }
                }
            }
        }

        int ret = INF;
        for (int i = 0; i < col; ++i) {
            ret = min(ret,minJump[row - 1][i]);
        }
        if(ret == INF){
            return -1;
        }
        else{
            return ret;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}