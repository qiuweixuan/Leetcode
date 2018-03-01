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
		//ͷ���
		ListNode* headNode = new ListNode(0);
		//��������ֽ��
		ListNode* curL1Node = l1;
		ListNode* curL2Node = l2;
		//����������ֽ�����һ�����
		ListNode* preResNode = headNode;



		//�ܺ�
		int sum = 0;
		do
		{
			/*
			ȡ��������ǰλ����ֵ�����ĳ������û�д�λ��������Ϊ0
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

			/* ��ǰλ������ */
			sum += (val1 + val2);
			int curVal = sum % 10;
			sum = sum / 10;

			
			/* 
			�洢��ͽ�������������
			�����½�� 
			*/
			ListNode* curResNode = new ListNode(curVal);

			preResNode->next = curResNode;

			preResNode = curResNode;
		

		} while (sum != 0 || curL1Node != NULL || curL2Node != NULL);/* û�д洢��������� */
		
		
		return headNode->next;
	}
};

