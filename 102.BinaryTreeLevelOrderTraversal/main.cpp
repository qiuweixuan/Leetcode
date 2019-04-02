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


/*class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelNodes;
        if(!root){
            return levelNodes;
        }

        int curLevelLen = 1;
        queue<TreeNode*> queueNodes;
        queueNodes.push(root);

        while (curLevelLen > 0){
            vector<int> curLevelNodes;
            int nextLevelLen = 0;
            for (int i = 0; i < curLevelLen; ++i) {
                TreeNode* node = queueNodes.front();

                queueNodes.pop();
                curLevelNodes.push_back(node->val);
                if(node->left){
                    queueNodes.push(node->left);
                    nextLevelLen++;
                }
                if(node->right){
                    queueNodes.push(node->right);
                    nextLevelLen++;
                }
            }
            levelNodes.push_back(curLevelNodes);
            curLevelLen = nextLevelLen;
        }

        return levelNodes;
    }
};*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelNodes;
        if(!root){
            return levelNodes;
        }

        int left = 0;
        int right = 1;
        vector<TreeNode*> vecQueueNodes;
        vecQueueNodes.push_back(root);

        while (left < right){
            int nextLevelLen = 0;
            vector<int> curLevelNodes;
            for (int i = left; i < right; ++i) {
                TreeNode* node = vecQueueNodes[i];
                curLevelNodes.push_back(node->val);
                if(node->left){
                    vecQueueNodes.push_back(node->left);
                    nextLevelLen++;
                }
                if(node->right){
                    vecQueueNodes.push_back(node->right);
                    nextLevelLen++;
                }
            }
            levelNodes.push_back(curLevelNodes);
            left = right;
            right = left + nextLevelLen;
        }

        return levelNodes;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}