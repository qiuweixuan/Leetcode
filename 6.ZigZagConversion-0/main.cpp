#include <iostream>
#include <algorithm>
#include <string>
#include <assert.h>
#include <sstream>
using namespace std;

//��һ���汾
/*
class Solution {
public:
    string convert(string s, int numRows) {
        //��������ж�

        if(numRows == 1){
            return s;
        }



        int strLen = s.size();
        string ret = "";

        int curRow = 1;

        //��һ�м���

        for (int i = curRow - 1; i < strLen; i += (numRows - 1) * 2) {
            ret += s[i];
        }
        curRow++;

        //�м��м���

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

        //���һ�м���

        for (int i = curRow - 1; i < strLen; i += (numRows - 1) * 2) {
            ret += s[i];
        }


        return ret;
    }
};
*/


//�ڶ����汾

/*class Solution {
public:
    string convert(string s, int numRows) {
        //��������ж�

        if(numRows == 1){
            return s;
        }



        int strLen = s.size();
        stringstream ret;

        int curRow = 1;

        //��һ�м���

        for (int i = curRow - 1; i < strLen; i += (numRows - 1) * 2) {
            ret << s[i];
        }
        curRow++;

        //�м��м���

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

        //���һ�м���

        for (int i = curRow - 1; i < strLen; i += (numRows - 1) * 2) {
            ret << s[i];
        }


        return ret.str();
    }
};*/


//�������汾
class Solution {
public:
    string convert(string s, int numRows) {
        //��������ж�
        int strLen = s.size();
        if(numRows == 1 || numRows >= strLen){
            return s;
        }

        //���ؽ��
        string ret = "";

        for (int curRow = 0; curRow < numRows; ++curRow) {
            //���е�һ���ַ�
            ret += s[curRow];

            //ǰһ���ַ��±�
            int firstIndex = curRow + (numRows - 1 - curRow) * 2;
            //��һ���ַ��±�
            int secondIndex = curRow + (numRows - 1) * 2;



            //ǰһ���ַ���δԽ��
            while (firstIndex < strLen){

                //���ǵ�һ�У�Ҳ�������һ��
                if(curRow != 0  &&  curRow != numRows - 1){
                    ret += s[firstIndex];
                    firstIndex += (numRows - 1) * 2;
                }

                //�ؼӺ�һ���ַ�
                if(secondIndex < strLen){
                    ret += s[secondIndex];
                    secondIndex += (numRows - 1) * 2;
                }
                else{
                    //��һ���ַ��Ѿ�������Χ
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