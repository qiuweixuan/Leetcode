#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>


using namespace std;


bool sortFunc(pair<int,int>& t1,pair<int,int>&t2){

    return t1.first <= t2.first;
}



int main() {
    int n;
    int d;

    cin >> n;
    cin >> d;

    vector<pair<int,int>> vec;
    for (int i = 0; i < n; ++i) {
        int dist,value;
        cin>>dist>>value;
        pair<int,int> p(dist,value);
        vec.push_back(p);
    }
    sort(vec.begin(),vec.end(),sortFunc);
    vector<int> maxWindow(vec.size(),0);

    int curSum = 0;
    for (int k = vec.size() - 1; k >= 0 ; --k) {
        curSum = max(curSum,vec[k].second);
        maxWindow[k] = curSum;
    }

    int sum = 0;
    int i = 0;
    int j = i + 1;
    for (int i = 0; i < vec.size() - 1; ++i) {
        while(j < vec.size()   && vec[j].first  - vec[i].first < d){
            j++;
        }
        if(j == vec.size()){
            break;
        }
        curSum = vec[i].second + maxWindow[j];
        sum = max(sum,curSum);
    }

    cout<<sum<<endl;

    return 0;
}