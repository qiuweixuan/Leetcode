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



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:

    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int i;
        for (i = 0; i < intervals.size() && intervals[i].start  < newInterval.start; ++i) {
        }
        intervals.insert(intervals.begin() + i,newInterval);

        return merge(intervals);
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ret;
        int i = 0;
        while(i < intervals.size()){
            int left = intervals[i].start;
            int right = intervals[i].end;
            i++;
            while(i < intervals.size() && right >= intervals[i].start){
                right = max(intervals[i].end,right);
                i++;
            }
            ret.push_back(Interval(left,right));
        }

        return ret;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}