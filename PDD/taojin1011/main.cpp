#include <iostream>
#include<algorithm>

using namespace std;


const int MAXN = 200;
const int MAXM = 200;

//金子地图

long long v[MAXN][MAXM];

//行上选择挖

long long t[MAXM];

//行上选择不挖

long long f[MAXM];


//某一行行最大值

long long l[MAXN];


long long func(long long * a,int len){

    t[len - 1] = a[len - 1];
    f[len - 1] = 0;

    for (int j = len - 2 ; j >= 0; --j) {
        t[j] = a[j] + f[j + 1];
        f[j] = max(t[j + 1],f[j + 1]);
    }

    long long ret  = max(t[0],f[0]);

    return ret;
}

int main() {

    //行数，列数

    int n,m;


    //多组数据

    while(cin >> n >> m){

        for (int i = 0; i < n ; ++i) {
            for (int j = 0; j < m; ++j) {
                cin>>v[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            l[i] = func(v[i],m);
        }

        long long ret =  func(l,n);

        cout<< ret << endl;



//        //求每一行最大值
//        for (int i = 0; i < n ; ++i) {
//
//            //递归终止（递推式起始）
//            t[m - 1] = v[i][m - 1]; //选
//            f[m - 1] = 0; //不选
//
//            for (int j = m - 2 ; j >= 0; --j) {
//                t[j] = v[i][j] + f[j + 1];//选  ：后一个必须不选   值 =  这一个坑的金子值 + 不选的结果
//                f[j] = max(t[j + 1],f[j + 1]);//不选  ：  后一个可选可不选   值 =  max( 可选，可不选）
//            }
//            //第一个格只有两种选择
//            l[i] = max(t[0],f[0]);
//        }
//
//        //求总的最大值
//
//        t[n - 1] = l[n - 1];
//        f[n - 1] = 0;
//
//        for (int j = n - 2 ; j >= 0; --j) {
//            t[j] = l[j] + f[j + 1];
//            f[j] = max(t[j + 1],f[j + 1]);
//        }
//
//        long long ret  = max(t[0],f[0]);
//
//        cout<< ret << endl;


    }



    return 0;
}