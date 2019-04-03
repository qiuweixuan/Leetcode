#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int maxJump(vector<int>& weights,int maxWeight){
    int count = 0;
    if(weights.empty()){ return count; }
    //����������
    sort(weights.begin(),weights.end());
    //Ԫ����ʹ�����
    vector<bool> isUsed(weights.size(),false);  int unusedElementsCount = weights.size();
    //��һ��������Ӧ������
    int curID = 0;
    while (unusedElementsCount > 0){
        //curID��������������������ӣ�δ�������˼���
        isUsed[curID] = true;  count++; unusedElementsCount--;
        //���ò��һ�飨û����һ���˿ͣ�
        if(unusedElementsCount == 0){  break; }
        //��һ����飬������curID��nextID���˲��ܳ�������СnextID����������������Ļ�飩
        int nextID = -1;
        for (int i = 0; i < weights.size(); ++i) {
            //δ���� && ���ߺ��ܳ���
            if(!isUsed[i] && weights[curID] + weights[i] > maxWeight){ nextID = i; break; }
        }
        //�Ҳ������صĻ�飬�Ǿ���ʣ����Ա������Ļ��
        if(nextID == -1){
            for (int i = 0; i < weights.size(); ++i) {
                if(!isUsed[i]){ nextID = i; break; }
            }
            //����һ�����
            isUsed[nextID] = true; unusedElementsCount--;
            //�趨��һ���˿ͣ���ʱһ����ʣ�������������
            curID = nextID + 1;
        }
        else{ //�ҵ����ػ�飬ֻ��curIDһ���˳���  //�趨��һ���˿ͣ���ʱ��ʹ֮ǰ�˿ͳ��صĻ��
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