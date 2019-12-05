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
    const int directX[4] = {0,1,0,-1};
    const int directY[4] = {1,0,-1,0};

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;

        int directID = 0;
        int x = 0,y = 0;
        int minX = 0,maxX = matrix.size() - 1;
        if(maxX < minX){
            return ret;
        }
        int minY = 0,maxY = matrix[0].size() - 1;
        if(maxY < minY){
            return ret;
        }
        int n = (maxX + 1) * (maxY + 1);

        for (int i = 0; i < n; ++i) {
            ret.push_back(matrix[x][y]);

            if(directID == 0 && y == maxY){
                directID = (directID + 1) % 4;
                minX++;
            } else if(directID == 1 && x == maxX){
                directID = (directID + 1) % 4;
                maxY--;
            } else if(directID == 2 && y == minY){
                directID = (directID + 1) % 4;
                maxX--;
            } else if(directID == 3 && x == minX){
                directID = (directID + 1) % 4;
                minY++;
            }

            x = x + directX[directID];
            y = y + directY[directID];
        }
        return ret;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}