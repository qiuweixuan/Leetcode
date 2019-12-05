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
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int len = 0;
        while (i >= 0 && s[i] == ' '){
            i--;
        }
        while (i >= 0 && s[i] != ' '){
            len++;
            i--;
        }
        return len;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}