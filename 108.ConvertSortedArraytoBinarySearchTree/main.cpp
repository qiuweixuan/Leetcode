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


/**
 * 利用有序数组特点，构造平衡二叉树（balance BST)
 * 方法：每次根节点选择当前数组元素的中间元素（mid = (lo + hi) / 2)
 */
class Solution {
private:
    //[lo,hi)
    TreeNode* buildTree(vector<int>& nums,int lo,int hi){
        if(lo >= hi){
            return NULL;
        }
        int mid = (lo + hi) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums,lo,mid);
        root->right = buildTree(nums,mid + 1,hi);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums,0,nums.size());
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}