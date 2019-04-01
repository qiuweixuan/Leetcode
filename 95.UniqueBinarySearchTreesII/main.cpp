#include <iostream>
#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0){
            return vector<TreeNode*>();
        }
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
        return genTrees(nums,0,n-1);
    }

private:
    vector<TreeNode*> genTrees(vector<int>& nums,int left,int right){
        vector<TreeNode*>retTrees;
        if(left > right){
            retTrees.push_back(NULL);
        } else if(left == right){
            TreeNode* root = new TreeNode(nums[left]);
            retTrees.push_back(root);
        } else{
            for(int mid = left;mid <= right;mid++){

                vector<TreeNode*> leftTrees = genTrees(nums,left,mid - 1);
                vector<TreeNode*> rightTrees = genTrees(nums,mid + 1,right);
                for(auto leftNode : leftTrees){
                    for (auto rightNode : rightTrees){
                        TreeNode* root = new TreeNode(nums[mid]);
                        root->left = leftNode;
                        root->right = rightNode;
                        retTrees.push_back(root);
                    }
                }
            }

        }
        return retTrees;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}