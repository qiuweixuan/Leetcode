#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using std::unordered_map;
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		//哈希表，此题也可以用普通TreeMap代替
		unordered_map<char, int> char2index;
		//初始化所有字母的下标
		for (char c = 'a'; c <= 'z'; c++)
		{
			char2index[c] = -1;
		}

		
		//初始化最大子串长度
		int maxLen = 0;
		//获取字符串总长度
		int strTotalLen = s.length();

		//初始化首尾指针,左闭右开模型
		int  start, end;
	
		//尾指针不断向后移
		for (start = 0, end = 0; end < strTotalLen; end++){
			//当前尾指针字母之前出现的下标
			int preIndex = char2index[s[end]];
			//查看是否当前子串产生了重复
			if (preIndex >= start)//重复
			{
				//计算当前长度，并判断是否需要更新
				int curLen = end - start;
				maxLen = maxLen > curLen ? maxLen : curLen;
				//更新首指针
				start = preIndex + 1;
			}
			
			//更新下标
			char2index[s[end]] = end;
		}

		//计算最后一个长子串，计算尾指针到底的长度
		maxLen = maxLen > end - start ? maxLen : end - start;
		

		//返回最佳结果
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