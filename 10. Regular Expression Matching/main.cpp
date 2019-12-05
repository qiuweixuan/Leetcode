#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//��һ���汾����������ɨ��

class Solution {
public:
    bool isMatch(string s, string p) {
        //��ȫƥ��
        if(s == p){
            return true;
        }

        //s��Ϊ�գ�pΪ����ƥ�� ---> �˴�ֻ���ж�p�Ƿ�Ϊ��
        if( p.empty() ){
            return false;
        }

        //p��Ϊ�յ����

        //p�еڶ���Ԫ������* ,���������ƥ��
        if(p.size() > 1 && p[1] == '*'){
            //s�ǿ�ʱ����s�����޸�
            /*
            if(!s.empty()){
                if(p[0] == '.'){ //�����ַ�
                    s = "";
                } else{ //�ض��ַ�
                    int i = 0;
                    while (s[i] == p[0] && i < s.size()){
                        i++;
                    }
                    s = s.substr(i);
                }
            }
            */
            //s�ǿգ���s[0]��ƥ��Ԫ��

            while (!s.empty() && (p[0] == '.' || s[0] == p[0])) {
                //ǰ�����ַ�������ƥ�䣬p�ĺ�׺��s����ƥ��  false״̬
                if (isMatch(s, p.substr(2))) return true;

                //ǰ�����ַ�����ƥ�䣬ÿ��ֻƥ��һ���ַ�   true״̬
                s = s.substr(1);
            }

            //p�޸�

            p = p.substr(2);
        }
        else{ //ƥ�䵥���ַ�

            //�޷�����ƥ��

            if(s.empty()){
                return false;
            }

            //s�ǿ�ʱ����s�����޸�

            if(p[0] == '.' || p[0] == s[0]){
                s = s.substr(1);
            }
            else {
                return false;
            }

            //p�޸�

            p = p.substr(1);
        }


        //��һ���ݹ�

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