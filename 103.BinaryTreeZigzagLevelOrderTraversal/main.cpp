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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levelNodes;
        if(!root){
            return levelNodes;
        }

        int left = 0;
        int right = 1;
        vector<TreeNode*> vecQueueNodes;
        vecQueueNodes.push_back(root);
        bool isPostiveOrder = true;

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
            vector<int> curLevelNodes;
            if(isPostiveOrder){
                for (int i = left; i < right; ++i) {
                    TreeNode* node = vecQueueNodes[i];
                    curLevelNodes.push_back(node->val);
                }
            }
            else{
                for (int  i = right - 1; i >= left ; --i){
                    TreeNode* node = vecQueueNodes[i];
                    curLevelNodes.push_back(node->val);
                }
            }

            levelNodes.push_back(curLevelNodes);
            left = right;
            right = left + nextLevelLen;
            isPostiveOrder = !isPostiveOrder;
        }
        return levelNodes;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}