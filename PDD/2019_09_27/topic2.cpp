#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

string word;
int solve_cost(const string& order){
    int cost = 0;
    int dist[26] = {0};
    for (size_t i = 0; i < order.size(); i++)
    {
        dist[order[i] - 'A'] = i + 1;
    }
    
    int prev = order[0] - 'A';
    for (size_t i = 0; i < word.size(); i++)
    {
       int cur = word[i] - 'A';
       int d = abs(dist[cur] - dist[prev]);
       cost += d;
       prev = cur;
    }
    

    return cost;
}

int search(const string& select,string order,int* isExist,int depth){

    int cost = 1000000009;
    if(depth == 0){
        cost = solve_cost(order);
        return cost;
    }


    for (size_t i = 0; i < select.size() && cost > 0; i++)
    {
        int c = select[i] - 'A';
        if(!isExist[c]){
            isExist[c] = 1;
            int cur_cost = search(select,order + select[i],isExist,depth - 1);
            cost = min(cost,cur_cost);
            isExist[c] = 0;
        }
    }
    return cost;
}



int main(){

    int n;
    cin>>n;
    string keys = "ASDFGH";
    
    for (size_t i = 0; i < n; i++)
    {
        int isExist[26] = {0};
        cin>>word;
        for (auto&& c: word)
        {
            isExist[c-'A'] = 1;
        }
        
        string select;
        for (size_t j = 0; j < 26; j++)
        {
            if(isExist[j]){
                  select += (char)('A' + j);
            }
            isExist[j] = 0;
        }
        string order;
        int cost = search(select,order,isExist,select.size());
        cout<<cost<<endl;
    }
    
    return 0;
}