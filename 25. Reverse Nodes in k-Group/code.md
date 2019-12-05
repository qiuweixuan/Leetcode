# 链表反转问题

##细心考虑问题分解过程即可


##求解方法

### 1. 将当前链表切分为三块： before -> cur -> next
   1.  before : 上一块的尾指针
   2.  cur : 当前块反转前的尾指针，反转后的头指针
   3.  after : 后一块的头指针


### 2. 当块内元素满足条件时，利用栈的FILO特点进行反转
   1. 使用栈保存反转元素
   2. 首先进行前中块链接
   3. 然后进行中间块反转
   4. 最后进行中后块链接




```c++
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

```
