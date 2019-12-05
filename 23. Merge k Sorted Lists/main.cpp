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
    int getHeadID(vector<ListNode*>& lists){
        const int MAX = 1000000007;
        int minID = -1;
        int minValue = MAX;

        for (int i = 0; i < lists.size(); ++i) {
            ListNode* cur = lists[i];
            if(cur ==  NULL){
                continue;
            }

            if(cur->val < minValue){
                minID = i;
                minValue = cur->val;
            }
        }

        return minID;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }

        int headID = getHeadID(lists);
        if(headID == -1){
            return NULL;
        }

        ListNode* head = lists[headID];
        lists[headID] = head->next;

        ListNode* preNode = head;
        int curID;
        ListNode* curNode;

        while ((curID=getHeadID(lists)) != -1){
            ListNode* curNode = lists[curID];

            preNode->next = curNode;
            preNode = curNode;

            lists[curID] = curNode->next;
        }

        return head;
    }
};

int main() {

    return 0;
}

