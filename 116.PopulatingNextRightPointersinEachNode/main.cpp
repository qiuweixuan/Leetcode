#include<iostream>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};




//Solution1 : parent_layer_ptr + child_layer_ptr
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }

        Node* parent_layer_ptr = root;
        Node* child_layer_ptr = root->left;
        

        int layer_couple = 1;
        while(child_layer_ptr != NULL){
            Node* parent = parent_layer_ptr;
            Node* child = child_layer_ptr;

            for (int i = 0; i < layer_couple - 1 ; i++)
            {
                //odd
                child->next = parent->right;
                child = child->next;

                //even
                parent= parent->next;
                child->next = parent->left;
                child = child->next;
            }

             //odd
            child->next = parent->right;
            child = child->next;
            //even
            child->next = NULL;

            parent_layer_ptr = child_layer_ptr;
            child_layer_ptr = parent_layer_ptr->left;
            layer_couple = layer_couple << 1;
        }

        return root;
    }
};

//Solution2 : parent_layer_ptr 
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return NULL;
        }

        Node* parent_layer_ptr = root;
        
        int layer_couple = 1;
        while(parent_layer_ptr->left != NULL){
            Node* parent = parent_layer_ptr;
    
            for (int i = 0; i < layer_couple - 1 ; i++ , parent = parent->next)
            {
                //odd
                parent->left->next = parent->right;

                //even
                parent->right->next = parent->next->left;
            }

            //odd
            parent->left->next = parent->right;

            //next layer
            parent_layer_ptr  = parent_layer_ptr->left;
            layer_couple = layer_couple << 1;
        }

        return root;
    }
};