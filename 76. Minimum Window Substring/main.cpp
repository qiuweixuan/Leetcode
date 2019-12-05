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
    string minWindow(string s, string t) {
        if(s.empty() || t.empty()){
            return "";
        }

        int countT[128] = {0};
        int countS[128] = {0};
        set<char> charSet;
        for (int i = 0; i < t.size(); ++i) {
            countT[t[i]]++;
            charSet.insert(t[i]);
        }



        int charComplete = 0;
        int left = 0,right = 0;
        int smallLen = s.size() + 1;
        string ret = "";

        while (left < s.size()){

            while (left < s.size() && charSet.find(s[left]) == charSet.end()){
                left++;
            }

            while (right < s.size() && charComplete < charSet.size()){
                char c = s[right];
                if(charSet.find(c) != charSet.end()){
                    countS[c]++;
                    if( countS[c] == countT[c]){
                        charComplete++;
                    }
                }
                right++;
            }
            if(charComplete < charSet.size()){
                break;
            }

            while (left < right){
                char c = s[left];
                if(charSet.find(c) != charSet.end()){
                    countS[c]--;
                    if( countS[c] < countT[c]){
                        charComplete--;
                        break;
                    }
                }
                left++;
            }

            int len = right - left;
            if(len < smallLen){
                ret = s.substr(left,len);
                smallLen = len;
            }
            left++;
        }

        return ret;
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
        string s = stringToString(line);
        getline(cin, line);
        string t = stringToString(line);

        string ret = Solution().minWindow(s, t);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}