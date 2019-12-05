#include<iostream>
#include<algorithm>


using namespace std;
const int MAX_SIZE = 100000;
int main(){
    int a[] = {3,3,3,3,4,5};
    int ele_count[MAX_SIZE] = 0;
    for (size_t i = 0; i < sizeof(a); i++)
    {
         ele_count[a[i]]++;
    }
    
}