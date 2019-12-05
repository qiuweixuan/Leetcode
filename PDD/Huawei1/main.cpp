#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool sortStr(string& str1,string& str2){
    if(str1[0] != str2[0]){
        return str1[0] < str2[0];
    }
    else{
        return str1.size() > str2.size();
    }
}
/*

class Solution {
public:
    bool check(string& input,int* isUsed,int i){
        return input[i] >= 'A' && input[i] <= 'Z' && i + 1 < input.size()
        && input[i + 1] == input[i] - 'A' + 'a' && !isUsed[input[i] - 'A'];
    }

    vector<string> solve(string& input) {
        vector<string> ret;
        int i = 0;
        int start = 0;
        int end = 0;
        int isUsed[26];
        fill(isUsed,isUsed + 26,0);
        int prevChar = 0;


        while (i < input.size()){
            if(check(input,isUsed,i)){
                start = i;
                prevChar = (int)(input[i] - 'A');
                isUsed[input[i] - 'A'] = 1;
                i = i + 2;
                while (i < input.size() && (input[i] - 'A') == (prevChar + 1) % 26 && check(input,isUsed,i)){
                    prevChar++;
                    isUsed[input[i] - 'A'] = 1;
                    i = i + 2;
                }
                end = i;
                ret.push_back(input.substr(start,end - start));
                fill(isUsed,isUsed + 26,0);
            } else{
                i++;
            }
        }
        sort(ret.begin(),ret.end(),sortStr);
        return ret;
    }
};
*/
class Solution {
public:
    

    vector<string> solve(string& input) {
        vector<string> ret;
        int count[128] = {0};
        int isUsed[26] = {0};
        for (int i = 0; i < input.size(); ++i) {
            count[input[i]]++;
        }

        for (char c = 'A';  c <= 'Z' ; c++) {
            count[c] = min(count[c] , count[c - 'A' + 'a']);
        }

        while (1){
            char start = 0;
            for (char c = 'A';  c <= 'Z' ; c++) {
                if(count[c]){
                    start = c;
                }
            }


        }


        
        sort(ret.begin(),ret.end(),sortStr);
        return ret;
    }
};


int main() {
    string input;
    cin>>input;
   vector<string> lists = Solution().solve(input);
   for(auto v : lists){
       cout<<v<<endl;
   }
   return 0;
}