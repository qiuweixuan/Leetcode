#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <stack>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k < 2){
            return head;
        }

        ListNode* dummary = new ListNode(0);
        dummary->next = head;

        ListNode* before = dummary;
        ListNode* cur = before->next;

        stack<ListNode*> nodeStack;
        int count = 0;
        while (cur){
            count++;
            if(count == k){

                //get after block head
                ListNode* after = cur->next;

                //link before block tail and  reversed cur block head
                before->next = cur;

                //reverse cur block
                while (!nodeStack.empty()){
                    ListNode* prev = nodeStack.top();
                    nodeStack.pop();

                    cur->next = prev;
                    cur = prev;
                }

                //link reversed cur block tail and  after block head
                cur->next = after;

                //reflash
                before = cur;
                cur = after;
                count = 0;
            }
            else{
                nodeStack.push(cur);
                cur = cur->next;
            }
        }

        ListNode* ret = dummary->next;
        delete(dummary);
        return ret;

    }
};

int main() {

    return 0;
}

