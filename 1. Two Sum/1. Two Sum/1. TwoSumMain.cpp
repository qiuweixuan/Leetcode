#include <iostream>
#include <vector>
#include <algorithm>
//#include <hash_map>
//using std::hash_map;
#include <unordered_map>
using std::unordered_map;
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		//哈希表
		//hash_map<int, int> value2index;
		unordered_map<int, int> value2index;
		//返回下标链表
		vector<int> res(2);

		//初始化哈希表，冲突值的下标记录最大下标
		int index = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); index++,it++){
			value2index[*it] = index;
		}

		//哈希查询
		index = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); index++, it++){
			int nextValue = target - *it;
			//哈希值存在
			if (value2index.find(nextValue) != value2index.end()){
				int nextIndex = value2index[nextValue];
				//下标不重复
				if (nextIndex != index){
					res[0] = index;
					res[1] = nextIndex;
					break;
				}
			}
		}

		//返回结果
		return res;
	}
};


int main(){
	int inputArray[] = { 2, 7, 9, 14 };
	int target = 9;
	int arraySize = sizeof(inputArray) / sizeof(int);
	vector<int> nums(inputArray,inputArray + arraySize);

	Solution sol =  Solution();
	vector<int> res = sol.twoSum(nums, target);
	
	for (vector<int>::iterator it = res.begin(); it != res.end();  it++){
		cout << *it << endl;
	}

	system("pause");
	return 0;
}
