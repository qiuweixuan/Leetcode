#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <stack>
using namespace std;

class Solution {
public:

    void generateLeaf(vector<string>& ret,string s,int leftN,int rightN){
        if(leftN == 0){
            for (int i = 0; i < rightN; ++i) {
                s += ')';
            }
            ret.push_back(s);
            return;
        }

        //left
        generateLeaf(ret,s + '(',leftN - 1,rightN);
        //right
        if(leftN < rightN){
            generateLeaf(ret,s + ')',leftN,rightN - 1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        if(n <= 0)
        {
            return ret;
        }
        string s;
        generateLeaf(ret,s,n,n);

        return ret;
    }
};

int main() {
    int n;
    while (cin >> n) {
        vector<string> ret = Solution().generateParenthesis(n);


        for (int i = 0; i < ret.size(); ++i) {
            cout<<ret[i]<<endl;
        }
    }
    return 0;
}

