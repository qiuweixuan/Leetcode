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
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> count(60,0);
        for (int i = 0; i < time.size(); ++i) {
            count[ time[i] % 60]++;
        }
        int ret = 0;
        if(count[0] >= 2){
            ret += count[0] * (count[0] - 1) / 2;
        }
        for (int i = 1; i < 30 ; ++i) {
            int j = 60 - i;
            ret += count[i] * count[j];
        }
        if(count[30] >= 2){
            ret += count[30] * (count[30] - 1) / 2;
        }

        return ret;
    }
};
int main() {
    int n;
    while(cin >> n){
        vector<int> time(n);
        for (int i = 0; i < n; ++i) {
            cin>>time[i];
        }
        cout<<Solution().numPairsDivisibleBy60(time)<<endl;
    }
    return 0;
}