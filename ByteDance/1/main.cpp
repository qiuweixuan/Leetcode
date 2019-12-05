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





int main() {
    int value [4] = {64,16,4,1};
    int n;
    cin>>n;
    n = 1024 - n;
    int count = 0;
    int i = 0;
    while (n > 0){
        int m =  n / value[i];
        count += m;
        n %= value[i];
        i++;
    }
    cout<<count<<endl;

    return 0;
}