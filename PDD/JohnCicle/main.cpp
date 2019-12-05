#include <iostream>

using namespace std;


int main() {
    int n;
    int k;
    int m;

    cin >> n;
    cin >> k;
    cin >> m;
    int save  = 0;

    for (int i = 2; i <= n  ; ++i) {
        save = (save + m ) % i;
    }

    save = ((save + k) % n );

    std::cout << save  << std::endl;
    return 0;
}