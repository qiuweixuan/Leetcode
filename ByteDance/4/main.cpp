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

    int n,m;
    cin>> n >> m;
    int a[100000];
    int maxL = 0;
    for (int i = 0; i < n; ++i) {
        int l;
        cin>>l;
        l = l * 100;
        a[i] = l;
        maxL = max(maxL,l);
    }
    int left = 1;
    int right = maxL + 1;

    while (left < right){
        int mid = (left + right) / 2;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += a[i] / mid;
        }
        if(count >= m){
            left = mid + 1;

        } else{
            right = mid;
        }
       // cout<<left<<" "<<right<<endl;
    }
    printf("%0.2f",(right - 1) / (100.0 ));


    return 0;
}