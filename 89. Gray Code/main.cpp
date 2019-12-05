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

class Solution {
public:
    vector<int> grayCode(int n) {

        if (n == 0){
            vector<int> ret;
            ret.push_back(0);
            return ret;
        }
        int elemSize = 1 << n;
        vector<int> ret(elemSize,0);
        for (int bit = 0; bit < n; ++bit) {
            bool isOne = false;
            int addValue = 1 << bit;
            int intervalDist = 1 << bit;

            int intervalSize = elemSize / ( intervalDist );
            for (int i = 0; i < intervalSize; ++i) {
                if(isOne){
                    for (int j = i * intervalDist; j < (i + 1) * intervalDist; ++j) {
                        ret[j] += addValue;
                    }
                }
                if(i % 2 == 0){
                    isOne = !isOne;
                }
            }
        }

        return ret;
    }
};

int main() {
    int n;
    while (cin>>n){
        auto list = Solution().grayCode(n);
        for (auto v :list){
            cout<<v<<" ";
        }
        cout<<endl;
    }
    return 0;
}