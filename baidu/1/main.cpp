#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int maxJump(vector<int>& weights,int maxWeight){
    int count = 0;
    if(weights.empty()){ return count; }
    //按体重排序
    sort(weights.begin(),weights.end());
    //元素已使用情况
    vector<bool> isUsed(weights.size(),false);  int unusedElementsCount = weights.size();
    //第一个人体重应该最轻
    int curID = 0;
    while (unusedElementsCount > 0){
        //curID必须乘坐，弹跳次数增加，未乘坐的人减少
        isUsed[curID] = true;  count++; unusedElementsCount--;
        //不用查找伙伴（没有下一个乘客）
        if(unusedElementsCount == 0){  break; }
        //找一个伙伴，是能让curID和nextID两人不能乘坐的最小nextID（满足条件里最轻的伙伴）
        int nextID = -1;
        for (int i = 0; i < weights.size(); ++i) {
            //未乘坐 && 两者和能超重
            if(!isUsed[i] && weights[curID] + weights[i] > maxWeight){ nextID = i; break; }
        }
        //找不到超重的伙伴，那就在剩余人员找最轻的伙伴
        if(nextID == -1){
            for (int i = 0; i < weights.size(); ++i) {
                if(!isUsed[i]){ nextID = i; break; }
            }
            //两人一起乘坐
            isUsed[nextID] = true; unusedElementsCount--;
            //设定下一个乘客，此时一定是剩余人中最轻的人
            curID = nextID + 1;
        }
        else{ //找到超重伙伴，只能curID一个人乘坐  //设定下一个乘客，此时是使之前乘客超重的伙伴
            curID = nextID;
        }
    }
    return count;
}


int main() {
    int n,m;
    cin>>n>>m;
    vector<int> weights;
    for (int i = 0; i < n; ++i) {
        int v;
        cin>>v;
        weights.push_back(v);
    }
    cout<<maxJump(weights,m)<<endl;
    return 0;
}
//6 6
//3 3 2 5 3 4