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
        vector<TreeNode*> trees;
        if(n <= 0){
            return trees;
        }

        vector<int>nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
        vector<vector<int>> permutaions = generatePermutaions(nums);
        for(auto list :permutaions){
            TreeNode* root = NULL;
            for(auto v : list){
                cout<<v<<" ";
                TreeNode* insertNode = new TreeNode(v);
                root = insertTree(root,insertNode);
            }
            cout<<endl;
            trees.push_back(root);
        }


        return trees;
    }

private:
    TreeNode* insertTree(TreeNode* root,TreeNode* insertNode){
        if(root == NULL){
            root = insertNode;
        }
        if(insertNode == NULL || insertNode->val == root->val){
            return root;
        }
        else if(insertNode->val < root->val){
            root->left = insertTree(root->left,insertNode);
        } else{
            root->right = insertTree(root->right,insertNode);
        }
        return root;
    }

    vector<vector<int>> generatePermutaions(vector<int>& nums){
        vector<vector<int>> ret;
        int depth = 0;
        recurPermutaion(ret,nums,0);
        return ret;
    }

    void recurPermutaion(vector<vector<int>>& ret,vector<int>& nums,int depth){
        if(depth == nums.size()){
            ret.push_back(nums);
            return;
        }
        recurPermutaion(ret,nums,depth + 1);
        for (int i = depth + 1; i < nums.size(); ++i) {
            swap(nums[depth],nums[i]);
            recurPermutaion(ret,nums,depth + 1);
            swap(nums[depth],nums[i]);
        }
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

