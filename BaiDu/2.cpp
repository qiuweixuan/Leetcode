#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
    int n,w;
    vector<int> volume;
    cin>>n>>w;
    for (size_t i = 0; i < n; i++)
    {
        int v;
        cin>>v;
        volume.push_back(v);
    }
    
    int sum_weights;

    int sum = 0;
    int middle = volume.size() / 2;
    for (size_t i = volume.size() - 1;i > middle ; i--)
    {
        int x =  i / 2;
        if(i % 2 == 1){
            if( i - 1 >= 1 ){
                volume[i - 1] = max(volume[i - 1] - volume[i],0);
            }
        }
        volume[x] = max(volume[x] - volume[i],0);
        sum += volume[i];
    }
    for (size_t i = 0;i <= middle ; i++)
    {
        int id = i * 2;
        if(id <= middle){
            volume[id] = max(volume[id] - volume[i],0);
        }
        id = i * 2  + 1;
        if(id <= middle){
            volume[id] = max(volume[id] - volume[i],0);
        }
        sum += volume[i];
    }   

    cout<<sum<<endl;

    return 0;
}