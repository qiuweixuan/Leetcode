#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include <vector>
using namespace std;


class Solution {
public:
    const  char R[10] = "IVXLCDM\0\0";
    const int V[7] = {1,5,10,50,100,500,1000};

    int getRIndex(char c){
        int id = -1;
        for (int i = 0; i < 7; ++i) {
            if(R[i] == c){
                id = i;
                break;
            }
        }
        return id;
    }

    int romanToInt(string s) {

        int ret = 0;

        while(!s.empty()){
            int id = getRIndex(s[0]);
            if(s.size() == 1){
                ret += V[id];
                break;
            }
            else{
                int nextID = getRIndex(s[1]);

                if(id % 2 == 0){

                    if(nextID == id){
                        int sublen = 0;

                        for (sublen = 0; sublen < s.size() && s[sublen] == R[id] ; ++sublen) {
                            ret += V[id];
                        }

                        s = s.substr(sublen);

                    } else if(nextID == id + 1){
                        ret += V[nextID] - V[id];

                        s = s.substr(2);
                    } else if(nextID == id + 2){
                        ret += V[nextID] - V[id];

                        s = s.substr(2);
                    }
                    else{
                        ret += V[id];
                        s = s.substr(1);
                    }
                } else{
                    if(nextID == id - 1){
                        int sublen = 0;

                        ret += V[id];

                        for (sublen = 1; sublen < s.size() && s[sublen] == R[nextID] ; ++sublen) {
                            ret += V[nextID];
                        }
                        s = s.substr(sublen);
                    } else{
                        ret += V[id];

                        s = s.substr(1);
                    }

                }
            }
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

        int ret = Solution().romanToInt(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}



class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }

        int minLen = 1000000007;
        int minID = -1;
        for (int i = 0; i < strs.size() ; ++i) {
            if(strs[i].size() < minLen){
                minID = i;
                minLen = strs[i].size();
            }
        }

        int i;
        for (i = 0; i < strs[minID].size(); ++i) {

            int j;
            for ( j = 0; j < strs.size() && strs[j][i] == strs[minID][i] ; ++j) {
            }

            if(j != strs.size()){
                break;
            }
        }

        string  ret = strs[minID].substr(0,i);
        return ret;
    }
};