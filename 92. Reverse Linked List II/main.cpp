#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <assert.h>
#include <stack>
#include <set>
#include <unordered_map>
#include <queue>
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m >= n){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 1; i < m; ++i) {
            prev = prev->next;
        }

        ListNode* left = prev->next;
        ListNode* right = left->next;
        left->next = right->next;
        right->next = left;
        prev->next = right;

        ListNode* start = right;
        ListNode* end = left;
        for (int i = m + 1; i < n; ++i) {
            ListNode* next = end->next;
            end->next = next->next;
            next->next = start;
            start = next;
            prev->next = start;
        }

        return dummy->next;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}