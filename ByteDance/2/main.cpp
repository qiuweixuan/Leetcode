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



int main() {
    int n;
    cin>>n;
    vector<string> strs;
    for (int j = 0; j < n; ++j) {
        string str;
        cin>>str;
        strs.push_back(str);
    }
    for (int i = 0; i < n; ++i) {
        string str = strs[i];
        int left = 0;

        while (left < str.size() - 1){
            if(str[left] == str[left + 1]){
                int right = left + 2;
                while (right < str.size() && str[left] == str[right]){
                    right++;
                }
                str.erase(left + 2,right - ( left + 2));
                left += 2;
            } else{
                left++;
            }
        }

        left = 0;
        while (left <= str.size() - 4){
            if(str[left] == str[left + 1] && str[left + 2] == str[left + 3]){
                str.erase(left + 2,1);
                left += 2;
            } else{
                left++;
            }
        }
        cout<<str<<endl;

    }

    return 0;
}