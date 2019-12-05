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
    int climbStairs(int n) {
        int step0 = 1;
        int step1 = 1;
        for (int i = 2; i <= n ; ++i) {
            int step2 = step0 + step1;
            step0 = step1;
            step1 = step2;
        }

        return step1;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}