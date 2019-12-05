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
    for (int i = 0; i < n; ++i) {
        int m;
        cin>>m;
        vector<int> a(m);
        int minID = -1;
        int minValue = 1000000007;

        for (int j = 0; j < m; ++j) {
            cin>>a[j];
            if(a[j] < minValue){
                minValue = a[j];
                minID = j;
            }
        }

        vector<int> nums(m,1);
        for (int j = 0; j < m; ++j) {
            int curID = (minID + j) % m;
            int nextID = (minID + j + 1) % m;
            if(a[curID] < a[nextID]){
                nums[nextID] = nums[curID] + 1;
            }
        }
        for (int j = 0; j < m; ++j) {
            int curID = (minID - j + m) % m;
            int nextID = (minID - j - 1 + m) % m;
            if(a[nextID] > a[curID] ){
                nums[nextID] = max(nums[nextID],nums[curID] + 1);
            }
        }
        int count = 0;
        for (int j = 0; j < m; ++j) {
            count += nums[j];
        }
        cout<<count<<endl;
    }


    return 0;
}