#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
/* 
int main(){

    int n,m;
    cin>>n;

    vector<int> outs;
    for (size_t i = 0; i < n; i++)
    {
       cin>>m;
       vector< pair<int,int> > points;
       set< pair<int,int> > res_set;
       for (size_t j = 0; j < m; j++)
       {
           pair<int,int> p;
           cin>>p.first>>p.second;
           points.push_back(p);
           res_set.insert(p);
       } 
      
    
        for (size_t j = 0; j < m; j++)
        {
            for (size_t k =  j + 1; k < m; k++)
            {
                int x = min(points[j].first,points[k].first);
                int y = min(points[j].second,points[k].second);
                res_set.insert(pair<int,int>(x,y));
            }
        }
        
        outs.push_back(res_set.size());
    }


    for (size_t i = 0; i < outs.size(); i++)
    {
        std::cout<<outs[i]<<endl;
    }
    
    return 0;
}
 */


int main(){

    int n,m;
    cin>>n;

    vector<int> outs;
    for (size_t i = 0; i < n; i++)
    {
       cin>>m;
       vector<long long> points;
       set<long long> res_set;
       for (size_t j = 0; j < m; j++)
       {
           long long  op1,op2;
           cin>>op1>>op2;
           long long combine = (op1 << 32) + op2;
           points.push_back(combine);
           res_set.insert(combine);
       } 
      
    
        for (size_t j = 0; j < m; j++)
        {
            for (size_t k =  j + 1; k < m; k++)
            {
                long long  x1 = points[j] >> 32;
                long long  y1 = points[j] - (x1 << 32);
                long long  x2 = points[k] >> 32;
                long long  y2 = points[k] - (x2 << 32);
                long long rop = ( min(x1,x2) << 32 ) + min(y1,y2);
                res_set.insert(rop);
            }
        }
        
        outs.push_back(res_set.size());
    }


    for (size_t i = 0; i < outs.size(); i++)
    {
        std::cout<<outs[i]<<endl;
    }
    
    return 0;
}