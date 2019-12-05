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
    int usedRow[100];
    int usedCol[100];
    int usedLeftSlant[100];
    int usedRightSlant[100];
    vector<vector<string>> solveNQueens(int n) {
        fill(usedRow,usedRow + n,0);
        fill(usedCol,usedCol + n,0);
        fill(usedLeftSlant,usedLeftSlant + (2 * n - 1),0);
        fill(usedRightSlant,usedRightSlant + (2 * n - 1),0);

        vector<vector<string>> ret;
        vector<string> graph(n,string(n,'.'));
        int usedQ = 0;
        solve(ret,graph,n,usedQ);

        return ret;
    }

    int totalNQueens(int n) {
        return solveNQueens(n).size();
    }

private:
    void solve(vector<vector<string>>& ret,vector<string>& graph,int n,int usedQ){
        if(n == usedQ){
            ret.push_back(graph);
            return;
        }

        int x = usedQ;
        for (int y = 0; y < n; ++y) {
            if(usedRow[x] || usedCol[y] || usedLeftSlant[x + y] || usedRightSlant[n - 1 + x - y]){
                continue;
            }
            usedRow[x] = usedCol[y] = usedLeftSlant[x + y] = usedRightSlant[n - 1 + x - y] = 1;
            graph[x][y] = 'Q';
            solve(ret,graph,n,usedQ + 1);
            graph[x][y] = '.';
            usedRow[x] = usedCol[y] = usedLeftSlant[x + y] = usedRightSlant[n - 1 + x - y] = 0;
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}