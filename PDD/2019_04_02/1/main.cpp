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


//bool sortFunc(pair<int,int>& t1,pair<int,int>&t2){
//
//    return t1.first <= t2.first;
//}

int main() {
    int n;

    int a[50],b[50];

    cin>>n;

    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    //vector<pair<int,int>> p;
    for (int i = 0; i < n; ++i) {
        cin>>b[i];
//        pair<int,int> e(b[i],i);
//        p.push_back(e);
    }

    sort(a,a + n);
    sort(b,b + n);
    //sort(p.begin(),p.end(),sortFunc);

    int sum = 0;

    for (int j = 0; j < n; ++j) {
        sum += a[j] * b[ n - j - 1];
    }

    cout<<sum<<endl;


    return 0;
}