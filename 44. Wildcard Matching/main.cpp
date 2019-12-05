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
/*
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() > 0 && p[0] == '*'){
            int i;
            for (i = 0; i + 1 < p.size() && p[i + 1] == '*' ; ++i) ;
            p = p.substr(i);
        }

        if(s.size() == 0 && p.size() == 0){
            return true;
        }
        else if(p.size() == 0){
            return false;
        }
        if(s.size() > 0){
            if( s[0] == p[0] || p[0] == '?'){
                return isMatch(s.substr(1),p.substr(1));
            }
            else if(p[0] == '*'){
                return isMatch(s,p.substr(1)) || isMatch(s.substr(1),p);
            } else{
                return false;
            }
        } else{
            if(p[0] == '*'){
                return isMatch(s,p.substr(1));
            } else{
                return false;
            }
        }
    }
};
*/
class Solution {
public:
    void preprocess(string& p){
        for (int i = 0; i < p.size(); ++i) {
            if (p[i] == '*'){
                int j;
                for (j = i + 1; j < p.size() && p[j] == '*' ; ++j) ;
                p = p.substr(0,i + 1) + p.substr(j);
            }
        }
    }

    bool isMatch(string s, string p) {
        preprocess(p);

        vector<vector<int> > cache(s.size() + 1);
        for (int k = 0; k < cache.size(); ++k) {
            vector<int> elem(p.size() + 1,-1);
            cache[k] = elem;
        }

        return matchDP(cache,s, p,0,0);

    }

    bool matchDP(vector<vector<int> > cache,string& s, string& p,int si,int pi) {
        int& ret = cache[si][pi];
        if(ret != -1){
            return (bool)ret;
        }

       while (si < s.size() && pi < p.size() && ( s[si] == p[pi] ||  p[pi] == '?')){
           si++;pi++;
       }

       if(pi == p.size()){
           if(si == s.size()){
               ret = 1;
           } else{
               ret = 0;
           }
           return (bool)ret;
       }

       if(p[pi] == '*'){
           /*if(matchDP(cache,s, p,si,pi + 1) || matchDP(cache,s, p,si + 1,pi))
           {
               ret = 1;
           } else{
               ret = 0;
           }
           return (bool)ret;*/
           for (int skip = 0; si + skip <= s.size(); ++skip) {
               if(matchDP(cache,s, p,si + skip,pi + 1)){
                   ret = 1;
                   return (bool)ret;
               }
           }
       }
       ret = 0;
       return (bool)ret;
    }

};



string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        string p = stringToString(line);

        bool ret = Solution().isMatch(s, p);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}