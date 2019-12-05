#include <iostream>
using namespace std;

class Solution {
public:


    double myPow(double x, int n) {


        if(x == 0.0){
            return 0;
        } else if(x == 1.0){
            return 1.0;
        } else if(x == -1.0){
            if(n % 2){
                return 1.0;
            } else{
                return -1.0;
            }
        }

        double result;
        if(n > 0){
            result = Pow(x,n);
        } else{
            if (n == -(1 << 30) * 2){
                result = 1.0 / ( Pow(x,abs(n + 1)) * x);
            } else{
                result = 1.0 / ( Pow(x,abs(n)));
            }

        }


        return result;
    }

private:
    double Pow(double x, int n) {
        if(n == 0){
            return 1.0;
        }
        if(n == 1){
            return x;
        }

        double result = Pow(x,n >> 1);
        result *= result;
        if(n % 2){
            result *= x;
        }

        return result;
    }
};

int main() {
    cout<< -(1 << 30) * 2<<endl;
    double d = Solution().myPow(2.00000,-2147483648);


    cout<<d<<endl;
}