#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<long long>> getCombine(int n)
{
    vector<vector<long long>> C(n+1, vector<long long>(n+1, 0));
    for (int i = 0; i <= n; i++) {
        C[i][i] = 1;
        C[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            C[j][i] = C[j-1][i-1] + C[j-1][i];
        }
    }
    return C;
}

int main(){
    int n,m,k;
    cin>> n >> m >> k;

    //异常处理
    if(k <= 0){
        return 0;
    }

    //获取组合数
    int v = max(n,m);
    auto&& c = getCombine(100);
    vector < vector<long long> > table(n + 1, vector<long long>(m + 1,0));

    //table表：a选i个 and b选j个时的组合数  aabba aaabb
    for (size_t i = 0; i <= n; i++)
    {
        for (size_t j = 0; j <= m; j++)
        {
            table[i][j] = c[i + j][i];
        }
    }
    

    //sum表：a选0到i个 and b选0到j个时的组合数
    vector < vector<long long> > sum(n + 1, vector<long long>(m + 1,0));
    for (size_t i = 0; i < m + 1; i++)
    {
        //sum[0][2] == 2 <---> "b" "bb"
        sum[0][i] = i;
    }
    for (size_t i = 1; i <= n; i++)
    {
        for (size_t j = 0; j <= m; j++)
        {
            //重合部分
            sum[i][j] = sum[i - 1][j];
            //a选i个，b选0,1,...,j个
            for (size_t k = 0; k <= j; k++)
            {
                sum[i][j] += table[i][k];
            }
            
        }
    }

    //二分法思想，将问题范围逐渐缩小，直至k == 0时为止（求解区间已不存在）
    while(k > 0)
    {
        //获取上半部大小
        long long top_size;
        if(n > 0){
            top_size = sum[n - 1][m] + 1;  // 可选(n-1)个a和可选m个b的组合 + 一个空字符串
        }
        else{
            top_size = 0;
        }

        //根据上半部大小判断选a还是选b
        if( k <= top_size){ //如果k在上半部
            cout<<"a"; //当前字符选定为a
            k--;  //减去空字符串
            n--; //a数量减少
        }
        else{ //如果k在下半部
            cout<<"b";//当前字符选定为b
            k = k - top_size;//减去上半部空间
            k--; //减去空字符串
            m--; //b数量减少
        }
        
    }
    cout<<endl;
    

    return 0;
}