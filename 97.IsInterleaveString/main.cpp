#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


//dp algorithm:
//isMatch[l1][l2] = top | left
/*
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool ret;
        if(s1.size() + s2.size() != s3.size()){
            ret = false;
            return ret;
        }
        vector<vector<bool> > isMatch(s1.size() + 1,vector<bool>(s2.size() + 1,false));

        isMatch[0][0] = true;
        for (int i = 1; i < s1.size() + 1; ++i) {
            isMatch[i][0] = isMatch[i - 1][0] && (s1[i - 1] == s3[i - 1]);
        }
        for (int j = 1; j < s2.size() + 1; ++j) {
            isMatch[0][j] = isMatch[0][j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i < s1.size() + 1; ++i) {
            for (int j = 1; j < s2.size() + 1; ++j) {
                bool top = isMatch[i - 1][j] && (s1[i - 1] == s3[i + j - 1]);
                bool left = isMatch[i][j - 1] && (s2[j - 1] == s3[i + j - 1]);
                isMatch[i][j] = top | left;
            }
        }

        return isMatch[s1.size()][s2.size()];
    }
};*/


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        bool ret;
        if(s1.size() + s2.size() != s3.size()){
            ret = false;
            return ret;
        }
        vector<bool>isMatch(vector<bool>(s2.size() + 1,false));

        isMatch[0] = true;
        for (int j = 1; j < s2.size() + 1; ++j) {
            isMatch[j] = isMatch[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i < s1.size() + 1; ++i) {
            isMatch[0] = isMatch[0] && (s1[i - 1] == s3[i - 1]);
            for (int j = 1; j < s2.size() + 1; ++j) {
                bool top = isMatch[j] && (s1[i - 1] == s3[i + j - 1]);
                bool left = isMatch[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                isMatch[j] = top | left;
            }
        }

        return isMatch[s2.size()];
    }
};


int main() {
    string s1,s2,s3;
    while(cin>>s1>>s2>>s3){

        bool output = Solution().isInterleave(s1,s2,s3);

        cout<<output<<endl;
    }
    return 0;
}