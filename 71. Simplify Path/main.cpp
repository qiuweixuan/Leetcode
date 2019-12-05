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
    string simplifyPath(string path) {
        int depth = 0;
        vector<string>dirs;

        int i = 0;
        while ( i < path.size()){
            if(path[i] == '/'){
                while (i < path.size() && path[i] == '/'){
                    i++;
                }
            } else{
                int left = i;
                while (i < path.size() && path[i] != '/'){
                    i++;
                }
                int right = i;
                dirs.push_back(path.substr(left,right - left));
            }
        }

        vector<string> vaildDirs(dirs.size());

        for (string dir : dirs){
            if(dir == "."){
                continue;
            } else if(dir == ".."){
                if(depth > 0){
                    depth--;
                }
            } else{
                vaildDirs[depth] = dir;
                depth++;
            }

        }

        string vaildPath = "/";
        for (int i = 0; i < depth - 1; ++i) {
            vaildPath += vaildDirs[i] + "/";
        }
        if(depth > 0){
            vaildPath += vaildDirs[depth - 1];
        }

        return vaildPath;
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
        string path = stringToString(line);

        string ret = Solution().simplifyPath(path);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}


