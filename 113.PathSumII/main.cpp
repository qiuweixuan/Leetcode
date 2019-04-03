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



class Solution {
public:
    void addPathSum(TreeNode* root, int sum,
            vector<vector<int> >& allPaths,vector<int>& curPath) {
        if(root == NULL){
            return ;
        }

        sum = sum - root->val;
        curPath.push_back(root->val);

        if(root->left == NULL && root->right == NULL){
            if(sum == 0){
                allPaths.push_back(curPath);
            }
        }
        addPathSum(root->left,sum,allPaths,curPath);
        addPathSum(root->right,sum,allPaths,curPath);

        curPath.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> allPaths;
        vector<int> curPath;
        addPathSum(root,sum,allPaths,curPath);
        return allPaths;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}