#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int sum = 0;

    int i = 0, str_size = s.size();
    while (i < str_size)
    {
        int v = 0;
        int start = i;
        while (i < str_size && s[i] != ';')
        {
            if (((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) == false)
            {
                v = -1;
            }
            i++;
        }

        if (v == -1)
        {
            v = 0;
        }
        else
        {
            int end = i - 1;
            v = abs(s[end] - s[start]);
        }
        sum += v;
        i++;
    }
    cout << sum << endl;

    return 0;
}