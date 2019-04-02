#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <limits.h>
#include <climits>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelNodes;
        if(!root){
            return levelNodes;
        }

        int left = 0;
        int right = 1;
        vector<TreeNode*> vecQueueNodes;
        vecQueueNodes.push_back(root);
        vector<int> levelsLen;
        levelsLen.push_back(1);

        while (left < right){
            int nextLevelLen = 0;
            for (int i = left; i < right; ++i) {
                TreeNode* node = vecQueueNodes[i];
                if(node->left){
                    vecQueueNodes.push_back(node->left);
                    nextLevelLen++;
                }
                if(node->right){
                    vecQueueNodes.push_back(node->right);
                    nextLevelLen++;
                }
            }
            left = right;
            right = left + nextLevelLen;
            if(nextLevelLen != 0){
                levelsLen.push_back(nextLevelLen);
            }
        }

        right = vecQueueNodes.size();
        for (int j = levelsLen.size() - 1; j >= 0; --j) {
            left = right - levelsLen[j];
            vector<int> curLevelNodes;
            for (int i = left; i < right; ++i) {
                curLevelNodes.push_back(vecQueueNodes[i]->val);
            }
            levelNodes.push_back(curLevelNodes);
            right = left;
        }

        return levelNodes;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}