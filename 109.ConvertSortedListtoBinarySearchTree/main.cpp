#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <limits.h>
#include <climits>
#include <vector>
#include <assert.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


/**
 * 利用有序数组特点，构造平衡二叉树（balance BST)
 * 方法：每次根节点选择当前数组元素的中间元素（mid = (lo + hi) / 2)
 * https://leetcode.com/articles/convert-sorted-list-to-binary-search-tree/
 */
class Solution {
private:
    ListNode* list = NULL;
    int getListSize(){
        int size = 0;
        ListNode* cur = list;
        while(cur != NULL){
            cur = cur->next;
            size++;
        }
        return size;
    }
    //[lo,hi)
    TreeNode* buildTree(int lo,int hi){
        if(lo >= hi){
            return NULL;
        }
        int mid = (lo + hi) / 2;
        //BST 先在左子树放置元素
        TreeNode* left = buildTree(lo,mid);
        //到当前子树的根时，放置当前节点值
        TreeNode* root = new TreeNode(this->list->val);
        list = list->next;
        root->left = left;
        //BST 之后继续在右子树放置元素
        TreeNode* right = buildTree(mid + 1,hi);
        root->right = right;
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        this->list = head;
        int size = this->getListSize();
        TreeNode* root = this->buildTree(0,size);
        this->list = NULL;
        return root;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}