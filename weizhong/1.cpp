#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int search(int end, vector<int> &arr)
{

    if (end <= 1)
    {
        return 0;
    }

    int max_id = -1;
    int max_v = 0;
    for (size_t j = 0; j < end; j++)
    {
        if (arr[j] >= max_v)
        {
            max_v = arr[j];
            max_id = j;
        }
    }

    if (max_v == 0)
    {
        return 0;
    }

    //not mov max_v element
    int sum_right = 0;
    for (size_t j = max_id + 1; j < end; j++)
    {
        sum_right += arr[j];
    }
    int left_cost = sum_right + search(max_id, arr);

    //mov max_v element
    arr[max_id] = 0;
    int right_cost = max_v + search(end, arr);
    arr[max_id] = max_v;

    return min(left_cost, right_cost);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (size_t i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        arr.push_back(v);
    }

        cout << search(arr.size(), arr) << endl;

    return 0;
}