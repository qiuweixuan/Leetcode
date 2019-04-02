#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <limits.h>
#include <climits>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
            return true;
        }
        else if(!p || !q){
            return false;
        }
        else{
            return p->val == q->val &&
                            isSameTree(p->left,q->left) &&
                            isSameTree(p->right,q->right);
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}