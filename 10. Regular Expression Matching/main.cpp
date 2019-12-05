#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//第一个版本：从左往右扫描

class Solution {
public:
    bool isMatch(string s, string p) {
        //完全匹配
        if(s == p){
            return true;
        }

        //s不为空，p为空则不匹配 ---> 此处只需判断p是否为空
        if( p.empty() ){
            return false;
        }

        //p不为空的情况

        //p有第二个元素且有* ,则进行连续匹配
        if(p.size() > 1 && p[1] == '*'){
            //s非空时，对s进行修改
            /*
            if(!s.empty()){
                if(p[0] == '.'){ //任意字符
                    s = "";
                } else{ //特定字符
                    int i = 0;
                    while (s[i] == p[0] && i < s.size()){
                        i++;
                    }
                    s = s.substr(i);
                }
            }
            */
            //s非空，且s[0]有匹配元素

            while (!s.empty() && (p[0] == '.' || s[0] == p[0])) {
                //前两个字符不进行匹配，p的后缀与s进行匹配  false状态
                if (isMatch(s, p.substr(2))) return true;

                //前两个字符进行匹配，每次只匹配一个字符   true状态
                s = s.substr(1);
            }

            //p修改

            p = p.substr(2);
        }
        else{ //匹配单个字符

            //无法进行匹配

            if(s.empty()){
                return false;
            }

            //s非空时，对s进行修改

            if(p[0] == '.' || p[0] == s[0]){
                s = s.substr(1);
            }
            else {
                return false;
            }

            //p修改

            p = p.substr(1);
        }


        //进一步递归

        return  isMatch(s,p);
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