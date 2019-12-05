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
    void normalize(vector<int>& num){
        num.push_back(0);
        for (int i = 0; i < num.size(); ++i) {
            int carry = num[i] / 10;
            num[i + 1] += carry;
            num[i] %= 10;
        }
        while (num.size() > 1 && num.back() == 0){
            num.pop_back();
        }
    }



    vector<int> multiplyByInt(const vector<int>& num1,const vector<int>& num2){
        vector<int> result(num1.size() + num2.size() + 1,0);
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                result[i + j] += num1[i] * num2[j];
            }
        }
        normalize(result);
        return result;
    }

    string multiply(string num1, string num2) {
        vector<int> intNum1;
        vector<int> intNum2;

        for (int i = num1.size() - 1; i >= 0 ; --i) {
            intNum1.push_back(int(num1[i] - '0'));
        }

        for (int i = num2.size() - 1; i >= 0 ; --i) {
            intNum2.push_back(int(num2[i] - '0'));
        }

        vector<int> intResult = multiplyByInt(intNum1,intNum2);

        string result;
        for (int i = intResult.size() - 1; i >= 0 ; --i) {
            result += char(intResult[i] + '0');
        }


        return result;
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);

        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}