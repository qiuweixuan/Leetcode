#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double res = 0;
		int totalLen = nums1.size() + nums2.size();
		if ((totalLen) % 2 == 1){
			res += findKthNum(nums1, 0, nums2, 0, totalLen / 2 + 1);
		}
		else
		{
			res += findKthNum(nums1, 0, nums2, 0, totalLen / 2 );
			res += findKthNum(nums1, 0, nums2, 0, totalLen / 2 + 1);

			res /= 2.0;
		}
		return res;
	}

	double findKthNum(vector<int>& nums1, int len1, vector<int>& nums2, int len2, int k){
		//保证有序性
		if (nums1.size() - len1 > nums2.size() - len2){
			return findKthNum(nums2, len2, nums1, len1, k);
		}
		//第一个数组（较短数组已空）
		if (len1 == nums1.size()){
			return nums2[len2 + k - 1];
		}
		//只取一个数
		if (k == 1){
			return min(nums1[len1], nums2[len2]);
		}

		//划分前k个元素给两个数组
		int partASize = min(k / 2, int(nums1.size() - len1));
		int partBSize = k - partASize;
		//利用定理,part*Size元素无需搜寻，缩小运算规模
		if (nums1[len1 + partASize - 1] < nums2[len2 + partBSize - 1]){
			return findKthNum(nums1, len1 + partASize, nums2, len2, k - partASize);
		}
		else if (nums1[len1 + partASize - 1] > nums2[len2 + partBSize - 1]){
			return findKthNum(nums1, len1 , nums2, len2 + partBSize, k - partBSize);
		}
		else//返回两个其中一个均可，因为相等
		{
			return nums1[len1 + partASize - 1];
		}
	}
};

int main(){

	vector<int> num1;
	num1.push_back(2);

	vector<int> num2;
	Solution sol = Solution();
	double value = sol.findMedianSortedArrays(num1, num2);
	cout << value << endl;
	system("pause");

	return 0;

}