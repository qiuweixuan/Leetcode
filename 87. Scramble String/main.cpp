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
    bool isScramble(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        else if(s1.size() != s2.size()){
            return false;
        }

        int count1[26] = {0};
        int count2[26] = {0};
        for(char c: s1){
            count1[c - 'a']++;
        }
        for(char c: s2){
            count2[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            if(count1[i] != count2[i]){
                return false;
            }
        }

        int size = s1.size();
        for (int i = 1; i <= size - 1; ++i) {
            bool unswapVaild = isScramble(s1.substr(0,i),s2.substr(0,i)) &&
                    isScramble(s1.substr(i,size - i),s2.substr(i,size - i));
            if(unswapVaild){
                return true;
            }
            bool swapVaild = isScramble(s1.substr(0,i),s2.substr(size - i,i)) &&
                    isScramble(s1.substr(i,size - i),s2.substr(0,size - i));
            if(swapVaild){
                return true;
            }
        }

        return false;
    }
};
int main() {
    string  s1,s2;
    while (cin>>s1>>s2){
        cout<<Solution().isScramble(s1,s2)<<endl;
    }
    return 0;
}