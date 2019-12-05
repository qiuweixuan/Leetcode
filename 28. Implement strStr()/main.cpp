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
    vector<int> getNext(string& pattern){
        vector<int> next(pattern.size(),0);
        next[0] = -1;
        int prefixMatch = -1;

        for (int i = 1; i < pattern.size(); ++i) {
            while (prefixMatch > -1 && pattern[prefixMatch + 1] != pattern[i]){
                prefixMatch = next[prefixMatch];
            }
            if(pattern[prefixMatch + 1] == pattern[i]){
                prefixMatch++;
            }
            next[i] = prefixMatch;
        }


        return next;
    }
    int getMatch(string& str,string& pattern,vector<int>& next){

        int prefixMatch = -1;

        for (int i = 0; i < str.size(); ++i) {
            while (prefixMatch > -1 && pattern[prefixMatch + 1] != str[i]){
                prefixMatch = next[prefixMatch];
            }
            if(pattern[prefixMatch + 1] == str[i]){
                prefixMatch++;
            }

            if(prefixMatch == pattern.size() - 1){
                return i - prefixMatch;
            }
        }
        return -1;
    }

    int strStr(string haystack, string needle) {
        if(haystack.size() == 0 && needle.size() == 0){
            return 0;
        }
        if(needle.size() == 0){
            return -1;
        }

        vector<int> next = getNext(needle);
        return  getMatch(haystack,needle,next);
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

int main() {
    string line;
    while (getline(cin, line)) {
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);

        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}