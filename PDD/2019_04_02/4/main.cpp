#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int MOD = 1000000007;
class Solution {
public:

    int generateLeaf(string s1,string s2,int leftN,int rightN){
        //cout<<s1<<" "<<s2<<endl;

        if(s1.size() == 0 && s2.size() == 0){
            return 1;
        }

        if(leftN < rightN){
            return 0;
        }

        int leftCount = 0,rightCount = 0;
        //left
        if(!s1.empty()){
            char c1 = s1[0];
            if(c1 == '('){
                leftCount  = generateLeaf(s1.substr(1),s2,leftN + 1,rightN);
            }
            else{
                leftCount  = generateLeaf(s1.substr(1),s2,leftN,rightN + 1);
            }
        }

        //right
        if(!s2.empty()){
            char c2 = s2[0];
            if(c2 == '('){
                rightCount  = generateLeaf(s1,s2.substr(1),leftN + 1,rightN);
            }
            else{
                rightCount  = generateLeaf(s1,s2.substr(1),leftN,rightN + 1);
            }
        }

        return (leftCount % MOD) +(rightCount % MOD) ;
    }

    int generateParenthesis(string str1,string str2) {


        return  generateLeaf(str1,str2,0,0);;
    }
};

int main() {
    string str1;
    string str2;
    cin>>str1>>str2;

    int ret = Solution().generateParenthesis(str1,str2);
    cout<<ret<<endl;

    return 0;
}
