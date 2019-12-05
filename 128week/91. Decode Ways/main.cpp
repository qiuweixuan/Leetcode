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
#include <queue>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        if(size == 0 || s == "0"){
            return 0;
        }

        vector<int> nums(size + 1);
        nums[size] = 1;
        nums[size - 1] = s[size - 1] == '0'? 0 : 1;

        for (int i = size - 2; i >= 0; --i) {
            int value = (s[i] - '0') * 10 + (s[i + 1] - '0');


            if(s[i] == '0'){
                nums[i] = 0;
            }
            else if(s[i + 1] == '0'){
                if(value > 20){
                    nums[i] = 0;
                }
                else{
                    nums[i] = nums[i + 2];
                }
            }
            else if(value <=  26){
                //split one char and two chars
                //climb stairs
                nums[i] = nums[i + 1] + nums[i + 2];

            } else{
                //split one char
                nums[i] = nums[i + 1];
            }
        }
        return nums[0];
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

        int ret = Solution().numDecodings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}



