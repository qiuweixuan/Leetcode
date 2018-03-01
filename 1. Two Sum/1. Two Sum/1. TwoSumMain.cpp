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
		//��ϣ��
		//hash_map<int, int> value2index;
		unordered_map<int, int> value2index;
		//�����±�����
		vector<int> res(2);

		//��ʼ����ϣ����ͻֵ���±��¼����±�
		int index = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); index++,it++){
			value2index[*it] = index;
		}

		//��ϣ��ѯ
		index = 0;
		for (vector<int>::iterator it = nums.begin(); it != nums.end(); index++, it++){
			int nextValue = target - *it;
			//��ϣֵ����
			if (value2index.find(nextValue) != value2index.end()){
				int nextIndex = value2index[nextValue];
				//�±겻�ظ�
				if (nextIndex != index){
					res[0] = index;
					res[1] = nextIndex;
					break;
				}
			}
		}

		//���ؽ��
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
