#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;




int main(){

    int n;
    cin>>n;
    int op1,op2,rop;
    int all_counts[10] = {0};

    for (size_t i = 0; i < n; i++)
    {
        vector<int> nums;
        cin>>op1>>op2;
        rop = op1 * op2;
        nums.push_back(op1),nums.push_back(op2),nums.push_back(rop);
        while (op2 > 0 )
        {
            int v = op2 % 10;
            op2 = op2 / 10;
            rop = op1 * v;
            nums.push_back(rop);
        } 
        int counts[10] = {0};
        for (size_t j = 0; j < nums.size(); j++)
        {
            rop = nums[j];
            while (rop > 0)
            {
                 int v = rop % 10;
                 rop = rop / 10;
                 counts[v] += 1;
                 all_counts[v] +=1;
            } 
        }
        
        for (size_t i = 1; i < 10; i++)
        {
            cout<<counts[i]<<" ";
        }
        cout<<endl;
    }

    int max_size = all_counts[1];
    int num = 1;
    for (size_t i = 1; i < 10; i++)
    {
        if(all_counts[i] > max_size){
            max_size = all_counts[i];
            num = i;
        }
    }
    cout<<num<<endl;

    return 0;
}