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
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        }
        sum = sum - root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == 0){
                return true;
            }
            else{
                return false;
            }
        }
        bool left = hasPathSum(root->left ,sum);
        bool right = hasPathSum(root->right,sum);
        return left || right;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}