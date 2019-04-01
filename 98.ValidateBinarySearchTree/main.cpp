#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
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

//使用二叉搜索树的特点，搜索时记录子树的区间大小
//这个性能好，可读性较差，代码有较多冗余

/*class Solution {
private:
    bool isVaildBSTWithMinMaxValue(TreeNode* root,int& minV ,int& maxV){

        if(root == NULL){
            return true;
        }
        else{
            if(root->val < minV){
                minV = root->val;
            }
            if(root->val > maxV){
                maxV = root->val;
            }

            bool leftIsBST = true;
            if(root->left){
                int leftMinV,leftMaxV;
                leftMinV = root->left->val;
                leftMaxV = root->left->val;
                leftIsBST =
                        isVaildBSTWithMinMaxValue(root->left,leftMinV,leftMaxV);
                leftIsBST = leftIsBST && (leftMaxV < root->val);
                if(leftMinV < minV){
                    minV = leftMinV;
                }
            }

            bool rightIsBST = true;
            if(root->right){
                int rightMinV,rightMaxV;
                rightMinV = root->right->val;
                rightMaxV = root->right->val;

                rightIsBST =
                        isVaildBSTWithMinMaxValue(root->right,rightMinV,rightMaxV);
                rightIsBST = rightIsBST && (root->val < rightMinV );
                if(rightMaxV > maxV){
                    maxV = rightMaxV;
                }
            }
            bool totalIsBST = (minV <= root->val && maxV >= root->val)
                   && leftIsBST && rightIsBST;

            return totalIsBST;
        }

    }
    const int MAX = 1000000007;
public:

    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int minV ,maxV;

//        minV = MAX;
//        maxV = -MAX;
        minV = root->val;
        maxV = root->val;
        return isVaildBSTWithMinMaxValue(root,minV,maxV);
    }
};*/

//可读性较佳，但是使用了两层函数递归调用（A->B->A递归调用），性能较差
class Solution {
private:
    //返回root树的区间[minV,maxV]，以及root是否是BST(isBST)
    bool searchVaildBST(TreeNode* root,int& minV,int& maxV){
        minV = root->val;
        maxV = root->val;
        bool isBST =  isVaildBSTWithMinMaxValue(root,minV,maxV);
        return isBST;
    }

    bool isVaildBSTWithMinMaxValue(TreeNode* root,int& minV ,int& maxV){
        //空节点与叶子节点
        if(root == NULL){
            return true;
        }
        else if(root->left == NULL && root->right == NULL){
            minV = root->val ,maxV = root->val;
            return true;
        }

        //当前区间
        minV = root->val ,maxV = root->val;
        //左子树与根节点整体有效性判断
        bool leftIsBST = true;
        if(root->left){
            //左区间
            int leftMinV,leftMaxV;
            leftIsBST = searchVaildBST(root->left,leftMinV,leftMaxV);
            leftIsBST = leftIsBST && (leftMaxV < root->val);
            //更新区间值
            if(leftMinV < minV){
                minV = leftMinV;
            }
        }

        //右子树与根节点整体有效性判断
        bool rightIsBST = true;
        if(root->right){
            //右区间
            int rightMinV,rightMaxV;
            rightIsBST = searchVaildBST(root->right,rightMinV,rightMaxV);
            rightIsBST = rightIsBST && (root->val < rightMinV );
            //更新区间值
            if(rightMaxV > maxV){
                maxV = rightMaxV;
            }
        }

        //三个部分整体性判断，确保万无一失
        bool totalIsBST = (minV <= root->val && maxV >= root->val)
                          && leftIsBST && rightIsBST;
        return totalIsBST;
    }

public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        int minV ,maxV;
        return searchVaildBST(root,minV,maxV);
    }
};




void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);

        bool ret = Solution().isValidBST(root);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
//[10,5,15,null,null,6,20]
//[2,1,3]
//[5,14,null,1]
//[2147483644,-2147483648,2147483646,null,null,2147483645,2147483647]