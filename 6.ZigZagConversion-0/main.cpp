#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
#include <sstream>
using namespace std;

//第一个版本
/*
class Solution {
public:
    string convert(string s, int numRows) {
        //特殊情况判断

        if(numRows == 1){
            return s;
        }



        int strLen = s.size();
        string ret = "";

        int curRow = 1;

        //第一行计算

        for (int i = curRow - 1; i < strLen; i += (numRows - 1) * 2) {
            ret += s[i];
        }
        curRow++;

        //中间行计算

        while(curRow < numRows){
            int dist1 = (numRows - curRow) * 2;
            int dist2 = (curRow - 1) * 2;

            int i = curRow - 1;
            while(1){
                if(i >= strLen){
                    break;
                }
                ret += s[i];
                i += dist1;

                if(i >= strLen){
                    break;
                }
                ret += s[i];
                i += dist2;
            }

            curRow++;
        }

        //最后一行计算

        for (int i = curRow - 1; i < strLen; i += (numRows - 1) * 2) {
            ret += s[i];
        }


        return ret;
    }
};
*/


//第二个版本

/*class Solution {
public:
    string convert(string s, int numRows) {
        //特殊情况判断

        if(numRows == 1){
            return s;
        }



        int strLen = s.size();
        stringstream ret;

        int curRow = 1;

        //第一行计算

        for (int i = curRow - 1; i < strLen; i += (numRows - 1) * 2) {
            ret << s[i];
        }
        curRow++;

        //中间行计算

        while(curRow < numRows){
            int dist1 = (numRows - curRow) * 2;
            int dist2 = (curRow - 1) * 2;

            int i = curRow - 1;
            while(1){
                if(i >= strLen){
                    break;
                }
                ret << s[i];
                i += dist1;

                if(i >= strLen){
                    break;
                }
                ret << s[i];
                i += dist2;
            }

            curRow++;
        }

        //最后一行计算

        for (int i = curRow - 1; i < strLen; i += (numRows - 1) * 2) {
            ret << s[i];
        }


        return ret.str();
    }
};*/


//第三个版本
class Solution {
public:
    string convert(string s, int numRows) {
        //特殊情况判断
        int strLen = s.size();
        if(numRows == 1 || numRows >= strLen){
            return s;
        }

        //返回结果
        string ret = "";

        for (int curRow = 0; curRow < numRows; ++curRow) {
            //该行第一个字符
            ret += s[curRow];

            //前一个字符下标
            int firstIndex = curRow + (numRows - 1 - curRow) * 2;
            //后一个字符下标
            int secondIndex = curRow + (numRows - 1) * 2;



            //前一个字符还未越界
            while (firstIndex < strLen){

                //不是第一行，也不是最后一行
                if(curRow != 0  &&  curRow != numRows - 1){
                    ret += s[firstIndex];
                    firstIndex += (numRows - 1) * 2;
                }

                //必加后一个字符
                if(secondIndex < strLen){
                    ret += s[secondIndex];
                    secondIndex += (numRows - 1) * 2;
                }
                else{
                    //后一个字符已经超出范围
                    break;
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);
        getline(cin, line);
        int numRows = stringToInteger(line);

        string ret = Solution().convert(s, numRows);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}