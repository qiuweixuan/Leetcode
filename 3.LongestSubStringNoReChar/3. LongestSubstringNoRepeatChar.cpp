#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using std::unordered_map;
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//��ϣ������Ҳ��������ͨTreeMap����
		unordered_map<char, int> char2index;
		//��ʼ��������ĸ���±�
		for (char c = 'a'; c <= 'z'; c++)
		{
			char2index[c] = -1;
		}

		
		//��ʼ������Ӵ�����
		int maxLen = 0;
		//��ȡ�ַ����ܳ���
		int strTotalLen = s.length();

		//��ʼ����βָ��,����ҿ�ģ��
		int  start, end;
	
		//βָ�벻�������
		for (start = 0, end = 0; end < strTotalLen; end++){
			//��ǰβָ����ĸ֮ǰ���ֵ��±�
			int preIndex = char2index[s[end]];
			//�鿴�Ƿ�ǰ�Ӵ��������ظ�
			if (preIndex >= start)//�ظ�
			{
				//���㵱ǰ���ȣ����ж��Ƿ���Ҫ����
				int curLen = end - start;
				maxLen = maxLen > curLen ? maxLen : curLen;
				//������ָ��
				start = preIndex + 1;
			}
			
			//�����±�
			char2index[s[end]] = end;
		}

		//�������һ�����Ӵ�������βָ�뵽�׵ĳ���
		maxLen = maxLen > end - start ? maxLen : end - start;
		

		//������ѽ��
		return maxLen;
	}
};


int main(){

	Solution sol = Solution();

	string s = "abcabcbb";
	cout << sol.lengthOfLongestSubstring(s) << endl;
	s = "bbbbb";
	cout << sol.lengthOfLongestSubstring(s) << endl;
	s = "pwwkew";
	cout << sol.lengthOfLongestSubstring(s) << endl;
	s = "p";
	cout << sol.lengthOfLongestSubstring(s) << endl;
	system("pause");
	return 0;
}