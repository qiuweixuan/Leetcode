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

/**
 * 易理解版本，但是浪费了空间
 */
/*

class Solution {
private:
    TreeNode* recurBuildTree(vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty()){
            return NULL;
        }
        //root
        int middleElem = preorder[0];
        TreeNode* root = new TreeNode(middleElem);

        int middleID; //leftLen
        for (middleID = 0; middleID < inorder.size()
                && middleElem != inorder[middleID]; ++middleID) {
        }

        //left preorder
        vector<int> leftTreePreorder(preorder.begin() + 1,preorder.begin() + (middleID + 1));
        //right preorder
        vector<int> rightTreePreorder(preorder.begin() + (middleID + 1),preorder.end());
        //left inorder
        vector<int> leftTreeInorder(inorder.begin(),inorder.begin() + middleID);
        //right inorder
        vector<int> rightTreeInorder(inorder.begin() + (middleID + 1),inorder.end());

        root->left = recurBuildTree(leftTreePreorder,leftTreeInorder);
        root->right = recurBuildTree(rightTreePreorder,rightTreeInorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = recurBuildTree(preorder,inorder);
        return root;
    }
};
*/



class Solution {
private:
    TreeNode* recurBuildTree(vector<int>& postorder, vector<int>& inorder,
                             int postLeft,int postRight,int inLeft,int inRight){
        if(postLeft >= postRight){
            return NULL;
        }
        //assert(preLeft < preRight && inLeft < inRight);

        //root
        int middleElem = postorder[postRight - 1];
        TreeNode* root = new TreeNode(middleElem);
        //leftLen,rightLen
        int middleID;
        for (middleID = inLeft; middleID < inRight
                                && middleElem != inorder[middleID]; ++middleID) {
        }
        int leftLen = middleID - inLeft;
        int rightLen = inRight - middleID - 1;
        
        //left tree
        int newPostLeft = postLeft;  int newPostRight = newPostLeft + leftLen;
        int newInLeft = inLeft;   int newInRight = inLeft + leftLen;
        root->left = recurBuildTree(postorder,inorder,
                                    newPostLeft,newPostRight,newInLeft,newInRight);
        //right tree
        newPostLeft = newPostRight,newPostRight = postRight - 1;
        newInLeft = newInRight + 1,newInRight = inRight;
        root->right = recurBuildTree(postorder,inorder,
                                     newPostLeft,newPostRight,newInLeft,newInRight);
        return root;
    }
public:
    TreeNode* buildTree( vector<int>& inorder,vector<int>& postorder) {
        if(postorder.empty()){
            return NULL;
        }
        int postLo = 0,postHi = postorder.size();
        int inLo = 0 ,inHi = inorder.size();
        TreeNode* root = recurBuildTree(postorder,inorder,
                                        postLo,postHi,inLo,inHi);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}