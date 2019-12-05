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
    string getPermutation(int n, int k) {
        string ret;
        string elements;
        for (int i = 0; i < n; ++i) {
            elements.push_back(char('1' + i));
        }

        k = k - 1;
        solve(ret,elements,n,k);

        return ret;
    }

private:
    /* void solve(string& ret,string& elements,int n ,int k){
        if(n == 0){
            return;
        }
        int len = 1;
        for (int i = 2; i <= n - 1; ++i) {
            len *= i;
        }

        int id = k / len;
        ret.push_back(elements[id]);
        elements.erase(id,1);

        n = n - 1;
        k = k % len;
        solve(ret,elements,n,k);
    }
*/
    void solve(string& ret,string& elements,int n ,int k){
        while (n > 0){
            int len = 1;
            for (int i = 2; i <= n - 1; ++i) {
                len *= i;
            }

            int id = k / len;
            ret.push_back(elements[id]);
            elements.erase(id,1);

            n = n - 1;
            k = k % len;
        }
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}