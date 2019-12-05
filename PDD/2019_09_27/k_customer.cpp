#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vals;
    for (size_t i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        vals.push_back(v);
    }

    map<int, int> val2idx;
    vector<vector<int>> idxs;
    int nums = 0;
    for (size_t i = 0; i < n; i++)
    {

        if (val2idx.count(vals[i]) == 0)
        {
            idxs.push_back(vector<int>());
            val2idx[vals[i]] = nums;
            nums++;
        }
        auto &&it = val2idx.find(vals[i]);
        int j = it->second;
        idxs[j].push_back(i + 1);
    }

    
    vector<int> results;
    int m;
    cin >> m;
    for (size_t i = 0; i < m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        auto &&it = val2idx.find(k);

        if (it == val2idx.end())
        {
            results.push_back(0);
            continue;
        }
        int j = it->second;
        int start = 0;
        int end = idxs[j].size();

        while (idxs[j][start] < l && start < end)
        {
            start++;
        }

        while (idxs[j][end - 1] > r && end > start)
        {
            end--;
        }

        int v = max(end - start, 0);
        results.push_back(v);
    }

    for (size_t i = 0; i < results.size(); i++)
    {
        cout << results[i] << endl;
    }

    return 0;
}
