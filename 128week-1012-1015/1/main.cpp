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
    int bitwiseComplement(int N) {
        vector<int> ret;
        int res = 0;
        if(N == 0){
            return 1;
        }
        else{
            while (N > 0){
                int c =  N & 1;
                ret.push_back(c);
                N = N >> 1;
            }
            for (int i = 0; i < ret.size(); ++i) {
                if(ret[i] == 0){
                    ret[i] = 1;
                }
                else{
                    ret[i] = 0;
                }
            }

        }

        for (int i = 0,n = 1; i < ret.size(); ++i, n = n << 1) {
            res += ret[i] * n;
        }

        return res;
    }
};
*/


class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0){
            return 1;
        }

        int bitLen = 0;
        int value = N;
        while(value > 0){
            bitLen++;
            value = value>>1;
        }
        int res =  (~N) & ((1 << bitLen) - 1) ;
        return res;
    }
};
int main() {
    int n;
    while(cin >> n){
        cout<<Solution().bitwiseComplement(n)<<endl;
    }

    return 0;
}