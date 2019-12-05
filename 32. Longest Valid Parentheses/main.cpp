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
    int longestValidParentheses(string s) {
        int maxCount = 0;
        stack<char> parenth;
        int curCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '('){
                parenth.push(s[i]);
            }
            else{

                if(parenth.size() > 0) {
                    char open = parenth.top();
                    parenth.pop();
                    if(open == '('){
                        curCount += 2;
                        maxCount = max(maxCount,curCount);
                    }
                }
                else{
                    maxCount = max(maxCount,curCount);
                    curCount = 0;
                    while (!parenth.empty()){
                        parenth.pop();
                    }
                }
            }
        }


        return maxCount;
    }
};*/



class Solution {
public:
    int longestValidParentheses(string s) {
        int maxCount = 0;
        int openCount = 0;
        int closeCount = 0;
        int curCount = 0;

        //左向扫描，正确状态左括号不少于右括号数量
        //平衡状态，此时左括号等于右括号数量，此时计数
        //错误状态时左右括号数量均清空
        //左向扫描时，无法计算正确状态下匹配数量（左括号会偏多）
        //此时应加入右向扫描

        for (int i = 0; i < s.size(); ++i) {
            if(s[i] == '('){
                openCount++;
            }
            else{
                closeCount++;
            }

            if(openCount == closeCount){
                curCount += closeCount * 2;

                maxCount = max(maxCount,curCount);
                openCount = closeCount = 0;

            } else if(openCount < closeCount){

                openCount = closeCount = 0;
                curCount = 0;
            }
        }

        openCount = closeCount = 0;
        curCount = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            if(s[i] == '('){
                openCount++;
            }
            else{
                closeCount++;
            }

            if(openCount == closeCount){
                curCount += closeCount * 2;
                maxCount = max(maxCount,curCount);

                openCount = closeCount = 0;
            } else if(openCount > closeCount){

                openCount = closeCount = 0;
                curCount = 0;
            }
        }


        return maxCount;
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

        int ret = Solution().longestValidParentheses(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}