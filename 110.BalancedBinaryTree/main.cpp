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
#include <cmath>
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
 * 利用递归方法获取左右子树的深度
 *
 */
class Solution {
private:
    int  getDepthAndBalance(TreeNode* root,bool& isCurTreeBalanced){
        if(root == NULL){
            return 0;
        }
        int leftDepth = getDepthAndBalance(root->left,isCurTreeBalanced);
        int rightDepth = getDepthAndBalance(root->right,isCurTreeBalanced);
        if(abs(leftDepth - rightDepth) > 1){
            isCurTreeBalanced = false;
        }
        int curDepth = max(leftDepth,rightDepth) + 1;
        return curDepth;
    }
public:
    bool isBalanced(TreeNode* root) {
        bool isCurTreeBalanced = true;
        getDepthAndBalance(root,isCurTreeBalanced);
        return isCurTreeBalanced;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}