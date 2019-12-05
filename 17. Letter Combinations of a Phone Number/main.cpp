#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
/*

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        map<char,string> dig2char;
        dig2char['1'] = "";
        dig2char['2'] = "abc";
        dig2char['3'] = "def";
        dig2char['4'] = "ghi";
        dig2char['5'] = "jkl";
        dig2char['6'] = "mno";
        dig2char['7'] = "pqrs";
        dig2char['8'] = "tuv";
        dig2char['9'] = "wxyz";

        vector<string> ret[2];

        int vaildStart = 0;
        while(vaildStart < digits.size() && digits[vaildStart] == '1') {
            vaildStart++;
        }

        if(vaildStart < digits.size()){
            string s = dig2char[digits[vaildStart]];
            for(int i = 0; i < s.size(); ++i) {
                ret[0].push_back(string(1,s[i]));
            }
            vaildStart++;
        }

        int curID = 0;
        for (int i = vaildStart; i < digits.size(); ++i) {
            if(digits[i] == '1'){
                continue;
            }

            int nextID = (curID + 1) % 2;
            string s = dig2char[digits[i]];
            ret[nextID].clear();

            for (int j = 0; j < ret[curID].size(); ++j) {
                string curStr = ret[curID][j];
                for (int k = 0; k < s.size(); ++k) {
                    string nextStr = curStr + s[k];
                    ret[nextID].push_back(nextStr);
                }
            }

            curID = nextID;
        }

        return ret[curID];
    }
};
*/
/*
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret[2];
        if(digits.empty()){
            return ret[0];
        }

        string dig2char[10];
        dig2char[2] = "abc";
        dig2char[3] = "def";
        dig2char[4] = "ghi";
        dig2char[5] = "jkl";
        dig2char[6] = "mno";
        dig2char[7] = "pqrs";
        dig2char[8] = "tuv";
        dig2char[9] = "wxyz";

        int curID = 0;
        string s = dig2char[digits[0] - '0'];
        for(int i = 0; i < s.size(); ++i) {
            ret[0].push_back(string(1,s[i]));
        }


        for (int i = 1; i < digits.size(); ++i) {

            int nextID = i % 2;
            ret[nextID].clear();
            s = dig2char[digits[i] - '0'];


            for (int j = 0; j < ret[curID].size(); ++j) {
                string curStr = ret[curID][j];
                for (int k = 0; k < s.size(); ++k) {
                    string nextStr = curStr + s[k];
                    ret[nextID].push_back(nextStr);
                }
            }
            curID = nextID;
        }

        return ret[curID];
    }
};*/


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty()){
            return ret;
        }

        string dig2char[10];
        dig2char[2] = "abc";
        dig2char[3] = "def";
        dig2char[4] = "ghi";
        dig2char[5] = "jkl";
        dig2char[6] = "mno";
        dig2char[7] = "pqrs";
        dig2char[8] = "tuv";
        dig2char[9] = "wxyz";


        string s = dig2char[digits[0] - '0'];
        for(int i = 0; i < s.size(); ++i) {
            ret.push_back(string(1,s[i]));
        }


        for (int i = 1; i < digits.size(); ++i) {


            s = dig2char[digits[i] - '0'];
            int len = ret.size();

            for (int j = 0; j < len; ++j) {
                string curStr = ret[j];

                ret[j] += s[0];
                for (int k = 1; k < s.size(); ++k) {
                    string nextStr = curStr + s[k];
                    ret.push_back(nextStr);
                }
            }

        }

        return ret;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}