#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		//头结点
		ListNode* headNode = new ListNode(0);
		//两链表的现结点
		ListNode* curL1Node = l1;
		ListNode* curL2Node = l2;
		//返回链表的现结点的上一个结点
		ListNode* preResNode = headNode;



		//总和
		int sum = 0;
		do
		{
			/*
			取两个数当前位的数值，如果某链表中没有此位，则设置为0
			*/
			int val1 = 0, val2 = 0;

			if (curL1Node != NULL){
				val1 = curL1Node->val;
				curL1Node = curL1Node->next;
			}

			if (curL2Node != NULL){
				val2 = curL2Node->val;
				curL2Node = curL2Node->next;
			}

			/* 当前位的运算 */
			sum += (val1 + val2);
			int curVal = sum % 10;
			sum = sum / 10;

			
			/* 
			存储求和结果到结果链表中
			插入新结点 
			*/
			ListNode* curResNode = new ListNode(curVal);

			preResNode->next = curResNode;

			preResNode = curResNode;
		

		} while (sum != 0 || curL1Node != NULL || curL2Node != NULL);/* 没有存储完继续运算 */
		
		
		return headNode->next;
	}
};

