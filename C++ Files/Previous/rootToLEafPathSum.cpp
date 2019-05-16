/*
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return

[
   [5,4,11,2],
   [5,8,4,5]
]
*/
#include <iostream>
#include <cmath>
#include <stack>
#include <vector>
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

void hasPathSumUtil(TreeNode* a, int sum , vector<vector<int> >& x,  vector<int>& q) {
    
    if(a == NULL){
        return;
    }
    q.push_back(a->val);
    if(sum == a->val && a->left == NULL && a->right == NULL){
            x.push_back(q);
    }
    hasPathSumUtil(a->left,sum - a->val , x, q);
    hasPathSumUtil(a->right,sum - a->val , x,q);
    q.pop_back();
}

vector<vector<int> > hasPathSum(TreeNode* a, int b) {
    vector<vector<int> > x;
    vector<int> q;
    int sumAdded = 0;
    hasPathSumUtil(a,b,x,q);
    return x;
}

int main(){
    TreeNode* root = newNode(5);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(11);
    root->right->left = newNode(13);
    root->right->right = newNode(4);
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(2);
    root->right->right->right = newNode(1);
    root->right->right->right = newNode(5);

    cout<<endl;
    vector<vector<int> > a = hasPathSum(root, 22);
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < a[i].size(); ++j)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
