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
/*

class Solution {
public:
    int maxRegionArea(vector<int>& heights,int left,int right){
        if(left > right){
            return 0;
        }
        else if(left == right){
            return heights[left];
        }
        int middle = (left + right) / 2;
        int leftArea = maxRegionArea(heights,left,middle);
        int rightArea = maxRegionArea(heights,middle + 1,right);
        int maxArea  = max(leftArea,rightArea);

        int h = min(heights[middle],heights[middle + 1]);
        int lo = middle,hi = middle + 1;
        while( lo >= left && hi <= right){
            h = min(h,min(heights[lo],heights[hi]));
            int middleArea = h * (hi - lo + 1);
            maxArea = max(maxArea,middleArea);

            if(lo == left){
                hi++;
            }
            else if(hi == right){
                lo--;
            } else{
                if(heights[lo - 1] > heights[hi + 1]){
                    lo--;
                } else{
                    hi++;
                }
            }
        }

        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        return maxRegionArea(heights,0,heights.size() - 1);
    }
};

*/



class Solution {
public:
    int maxRegionArea(vector<int>& heights,int left,int right){
        if(left > right){
            return 0;
        }
        else if(left == right){
            return heights[left];
        }
        int middle = (left + right) / 2;
        long long leftArea = maxRegionArea(heights,left,middle);
        long long rightArea = maxRegionArea(heights,middle + 1,right);
        long long maxArea  = max(leftArea,rightArea);

        int h = min(heights[middle],heights[middle + 1]);
        int lo = middle,hi = middle + 1;

        while(h * (long long)(right - left + 1) > maxArea && lo >= left && hi <= right){
            h = min(h,min(heights[lo],heights[hi]));
            long long middleArea = h * (hi - lo + 1);
            maxArea = max(maxArea,middleArea);

            if(lo == left){
                hi++;
            }
            else if(hi == right){
                lo--;
            } else{
                if(heights[lo - 1] > heights[hi + 1]){
                    lo--;
                } else{
                    hi++;
                }
            }
        }

        return (int)maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        return maxRegionArea(heights,0,heights.size() - 1);
    }
};





int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}