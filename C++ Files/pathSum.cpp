Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem*/
#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* newNode(int val){
    TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left = NULL;
    root->right = NULL;
    root->val = val;
    return root;
}

void hasPathSumUtil(TreeNode* a, int sumRemain, int& status) {
    if(a == NULL){
        return;
    }
    if(sumRemain == a->val && a->left == NULL && a->right == NULL){
        status = 1;
    }
    hasPathSumUtil(a->left,sumRemain - a->val, status);
    hasPathSumUtil(a->right,sumRemain - a->val, status);
}

int hasPathSum(TreeNode* a, int b) {
    int status = 0;
    hasPathSumUtil(a,b, status);
    if(status == 1){
        return 1;
    }
    return 0;
}

int main(){
    TreeNode* root = newNode(5);
    root->left = newNode(1000);
    root->right = newNode(200);
    // root->left->left = newNode(11);
    // root->right->left = newNode(13);
    // root->right->right = newNode(4);
    // root->left->left->left = newNode(7);
    // root->left->left->right = newNode(2);
    // root->right->right->right = newNode(1);

    // inorderTraversal(root);
    cout<<endl;
    cout<<hasPathSum(root, 1000);
}
