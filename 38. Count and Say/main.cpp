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
    string countAndSay(int n) {
        string curStr = "1";


        for (int i = 0; i < n - 1; ++i) {
            int count = 1;
            char curChar = curStr[0];
            string nextStr;

            for (int j = 1; j < curStr.size(); ++j) {
                char c = curStr[j];
                if( c == curChar){
                    count++;
                }
                else{
                    char num = (char)count + '0';
                    nextStr += num;
                    nextStr += curChar;

                    count = 1;
                    curChar = c;
                }
            }
            char num = (char)count + '0';
            nextStr += num;
            nextStr += curChar;

            curStr = nextStr;
        }

        return curStr;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}