#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

using namespace std;


int main() {
    int n, m;
    double val;
    vector<vector<int>> v;

    while(cin >> n >> m) {
        v.clear();
        v.reserve(n);

        for(int i=0; i<n; i++) {
            v.push_back(vector<int>());
            v[i].reserve(m);

            for(int j=0; j<m; j++) {
                cin >> val;
                v[i].push_back(val);
            }
        }

        vector<int> opt, lineSum, optLines;
        for(auto line : v) {
            opt.clear();
            if(line.size() > 0) {
                opt.push_back(line[0]);
            }
            if(line.size() > 1) {
                opt.push_back(max(line[0], line[1]));
            }
            for(int i=2; i< line.size(); i++) {
                opt.push_back(max(opt[i-1], opt[i-2]+line[i]));

            }
            lineSum.push_back(opt.back());
        }

        if(v.size() > 0) {
            optLines.push_back(lineSum[0]);
        }
        if(v.size() > 1) {
            optLines.push_back(max(lineSum[0], lineSum[1]));
        }
        for(int i=2; i<lineSum.size(); i++) {
            optLines.push_back(max(optLines[i-1],lineSum[i]+optLines[i-2]));
        }
        cout << optLines.back() << endl;

        lineSum.clear();
        optLines.clear();
    }
    return 0;
}