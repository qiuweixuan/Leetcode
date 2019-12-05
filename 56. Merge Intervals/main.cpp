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

    bool static sortInterval(Interval& i1,Interval& i2){
        return i1.start <= i2.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {

        vector<Interval> ret;
        sort(intervals.begin(),intervals.end(),sortInterval);
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


/*

class Solution {
public:

    bool static sortInterval(Interval& i1,Interval& i2){
        return i1.start <= i2.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {


        sort(intervals.begin(),intervals.end(),sortInterval);
        int i = 0;
        int size = 0;
        while(i < intervals.size()){
            int left = intervals[i].start;
            int right = intervals[i].end;
            i++;
            while(i < intervals.size() && right >= intervals[i].start){
                right = max(intervals[i].end,right);
                i++;
            }
            intervals[size].start = left;
            intervals[size].end = right;
            size++;
        }
        intervals.resize(size);

        return intervals;
    }
};
*/


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}