#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        long long  positive = x;
        long long reverse = 0;

        while (positive > 0){
            reverse += positive % 10;
            reverse *= 10;
            positive /= 10;
        }
        reverse /= 10;

        return x == reverse;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}