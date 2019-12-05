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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* dummary = new ListNode(0);

        ListNode* prev = dummary;
        ListNode* cur = head;


        while (cur != NULL && cur->next != NULL){
            ListNode* next = cur->next;
            prev->next = next;
            cur->next = next->next;
            next->next = cur;

            prev = cur;
            cur = cur->next;
        }

        ListNode* ret = dummary->next;
        return ret;
    }
};

int main() {

    return 0;
}

