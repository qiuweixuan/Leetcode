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
    string addBinary(string a, string b) {
        if(a.size() < b.size()){
            swap(a,b);
        }

        stack<int> sum;
        int carry = 0;
        for(int i = 0; i < b.size(); ++i) {
            int v = (b[ b.size() - i - 1] - '0') + (a[ a.size() - i - 1] - '0') + carry;
            sum.push(v % 2);
            carry = v / 2;
        }

        int remain = a.size() - b.size();
        for(int i = 0; i < remain; ++i) {
            int v = (a[remain - i - 1] - '0') + carry;
            sum.push(v % 2);
            carry = v / 2;
        }
        if(carry){
            sum.push(carry);
        }

        string ret;
        while (sum.size() > 0){
            ret.push_back(char(sum.top() + '0'));
            sum.pop();
        }

        return ret;
    }
};

/*

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()){
            swap(a,b);
        }


        string ret;
        //stack<int> sum;
        int carry = 0;
        for(int i = 0; i < b.size(); ++i) {
            int v = (b[ b.size() - i - 1] - '0') + (a[ a.size() - i - 1] - '0') + carry;
            //sum.push(v % 2);
            ret = char(v % 2 + '0') + ret;
            carry = v / 2;
        }

        int remain = a.size() - b.size();
        for(int i = 0; i < remain; ++i) {
            int v = (a[remain - i - 1] - '0') + carry;
            //sum.push(v % 2);
            ret = char(v % 2 + '0') + ret;
            carry = v / 2;
        }
        if(carry){
            //sum.push(carry);
            ret = char(carry + '0') + ret;
        }


//        while (sum.size() > 0){
//            ret += char(sum.top() + '0');
//            sum.pop();
//        }

        return ret;
    }
};
*/




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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
