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


/*
class Solution {
public:
    bool isVaild(vector<int>& partSum, int D,int top,int left,int right,vector<int>& minVolume){
        if(left == right)
        {
            return true;
        } else if(D == 0){
            return false;
        }
        if(top >= minVolume[left]){
            return true;
        }

        int n = partSum.size() - 1;
        for (int i = right; i >=  left + 1; --i) {
            if(partSum[i] - partSum[left] <= top && isVaild(partSum,D - 1 , top,i,right,minVolume)){
                minVolume[left] = min(minVolume[left],top);
                return true;
            }
        }

        return false;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int maxWeight = 0;
        int sumWeight = 0;

        vector<int> partSum(weights.size() + 1,0);
        for (int i = 0; i < weights.size(); ++i) {
            maxWeight = max(maxWeight,weights[i]);
            sumWeight += weights[i];
            partSum[i + 1] = partSum[i] + weights[i];
        }

        if(weights.size() <= D){
            return maxWeight;
        }
        vector<int> minVolume(weights.size(),sumWeight);

        int left = maxWeight;
        int right = sumWeight + 1;
        int minMid = sumWeight;
        while (left < right){
            int mid = (left + right) / 2;
            if(isVaild(partSum,D,mid,0,weights.size(),minVolume)){
                minMid = min(minMid,mid);
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        return minMid;
    }
};*/




class Solution {
public:
    int needDay(vector<int>& weights,int limitWeight){
        int day = 1;
        int curWeight = 0;
        for (int w :weights){
            if(curWeight + w > limitWeight){
                day++;
                curWeight = w;
            }
            else{
                curWeight += w;
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        int maxWeight = 0 ,sumWeight = 0;
        for (int i = 0; i < weights.size(); ++i) {
            maxWeight = max(maxWeight,weights[i]);
            sumWeight += weights[i];
        }
        if(weights.size() <= D){
            return maxWeight;
        }

        int left = maxWeight ,right = sumWeight + 1;
        int minMid = sumWeight;
        while (left < right){
            int mid = (left + right) / 2;
            if(needDay(weights,mid) <= D){
                minMid = min(minMid,mid);
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }

        return minMid;
    }
};


int main() {
    int n,d;
    while(cin >> n >> d){
        vector<int> time(n);
        for (int i = 0; i < n; ++i) {
            cin>>time[i];
        }
        cout<<Solution().shipWithinDays(time,d)<<endl;
    }
    return 0;
}
