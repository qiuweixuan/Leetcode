#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <limits.h>

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
/*
 * 方法一：中序遍历加数组上的双向扫描
 * （1）首先使用o(n）的额外空间存放树上的各个节点
 * （2） 然后对数组进行双向扫描，找出逆序关系的两个元素
 *  (3) 交换两个元素的卫星值，从而保证不改变树的结构
 */
class Solution1 {
public:
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inorderNodes;
        inorderSearchTree(root,inorderNodes);
        int left;
        for (left = 0; left < inorderNodes.size() - 1; ++left) {
            if(inorderNodes[left]-> val > inorderNodes[left + 1]->val){
                break;
            }
        }
        int right;
        for (right = inorderNodes.size() - 1; right > 0; --right) {
            if(inorderNodes[right - 1]-> val > inorderNodes[right]->val){
                break;
            }
        }

        if(left < right){
            swap(inorderNodes[left]->val,inorderNodes[right]->val);
        }
    }

    void searchTreeWithFP(TreeNode* root,void (*func)(TreeNode*)){
        if(root == NULL){
            return;
        }
        searchTreeWithFP(root->left,func);
        func(root);
        searchTreeWithFP(root->right,func);
    }

    void inorderSearchTree(TreeNode* root,vector<TreeNode*>& inorderNodes){
        if(root == NULL){
            return;
        }
        inorderSearchTree(root->left,inorderNodes);
        inorderNodes.push_back(root);
        inorderSearchTree(root->right,inorderNodes);
    }
};




/*
 * 方法二：只是用o(1）的额外空间进行查找
 *  将问题转化为在BST中：
 *  （1）找到下一个元素（比当前元素“大”的第一个元素）
 *  （2）找到上一个元素（比当前元素“小”的第一个元素）
 *
 *  找下一个元素的方法
 *  （1）当前节点有右子树：
 *          则查找右子树的最小节点（最左节点）
 *  （2）当前节点没有右子树：
 *          向祖先回溯，直至祖先节点的左子树包含当前节点
 *      即父节点一定是左子树中上一个节点的下一个节点
 */

/*
 * 方法三：只是用o(1）的额外空间进行查找
 *  将问题转化为在BST中查找相邻的逆序关系：
 *  （1）找到左失序元素（pre->val > cur->val)
 *  （2）找到右失序元素（cur->val > next->val）
 *
 */

class Solution{
private:

//    void searchLeftMistake(TreeNode* cur,TreeNode* &prev,TreeNode* &mistake){
//        if(cur && !mistake){
//            cout<<"cur1:"<<cur->val<<endl;
//            //左子树找prev
//            searchLeftMistake(cur->left,prev,mistake);
//            //发生失序关系
//            if(prev->val > cur->val){
//                mistake = prev;
//                return;
//            }
//            prev = cur;
//            //右子树中继续找失序关系
//            searchLeftMistake(cur->right,prev,mistake);
//        }
//    }


//    void searchRightMistake(TreeNode* cur,TreeNode* &next,TreeNode* &mistake){
//        if(cur && !mistake){
//            cout<<"cur2:"<<cur->val<<endl;
//            cout<<"next2:"<<next->val<<endl;
//            //右子树找next
//            searchRightMistake(cur->right,next,mistake);
//            //发生失序关系
//            if(next->val < cur->val ){
//                mistake = next;
//                cout<<mistake->val<<endl;
//                return;
//            }
//            next = cur;
//            cout<<next->val<<endl;
//            if(cur->left)
//            cout<<cur->left->val<<endl;
//            //左子树中继续找失序关系
//            searchRightMistake(cur->left,next,mistake);
//        }
//    }
public:
    void recover(TreeNode *root, TreeNode *&pre, TreeNode *&a, TreeNode *&b) {
        if (root)
        {
            recover(root->left, pre, a, b);

            if (root->val < pre->val)
            {
                if (!a) a = pre; //a should change once.
                b = root; //b could change twice.
            }
            pre = root;

            recover(root->right, pre, a, b);
        }
    }
    void recoverTree(TreeNode* root) {

       TreeNode prev =  TreeNode(numeric_limits<int>::min());
       TreeNode* leftMistake = NULL;
       TreeNode* rightMistake = NULL;
       TreeNode* p = &prev;
       TreeNode* cur = root;
       recover(cur,p,leftMistake,rightMistake);
       //searchLeftMistake(cur,p,leftMistake);



//       TreeNode next = TreeNode(numeric_limits<int>::max());
//       TreeNode* rightMistake = NULL;
//       TreeNode* n = &next;
//        cur = root;
//       searchRightMistake(cur,n,rightMistake);


       if(leftMistake && rightMistake ){
           swap(leftMistake->val,rightMistake->val);
       }
    }

    void searchTreeWithFP(TreeNode* root,void (*func)(TreeNode*)){
        if(root == NULL){
            return;
        }
        searchTreeWithFP(root->left,func);
        func(root);
        searchTreeWithFP(root->right,func);
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

void printfNodes(TreeNode* node){
    cout<<node->val<<" ";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        Solution().recoverTree(root);
        Solution().searchTreeWithFP(root,printfNodes);
        cout<<endl;
    }
    return 0;
}
//[1,3,null,null,2]
//[3,1,4,null,null,2]
//[2,1,4,null,null,3]