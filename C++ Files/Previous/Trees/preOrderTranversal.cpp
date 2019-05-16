
/* not completed yet  */

#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

struct binaryTree{
	int data;
	binaryTree* left;
	binaryTree* right;
};

binaryTree* newNode(int data){
	binaryTree* root = (struct binaryTree*)malloc(sizeof(struct binaryTree));
	root->left = NULL;
	root->right = NULL;
	root->data = data;
	return root;
}
void preorderTraversal(binaryTree* root){
	if(root == NULL){
		return;
	}
	cout<<root->data<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void preorderTraversalWithoutRecursion(binaryTree* root){
	if(root == NULL){
		return;
	}
	cout<<"a";
	stack<binaryTree*> s;
	s.push(root);
	while(!s.empty()){
		binaryTree* a = s.top();
		cout<<a->data<<" ";
		s.pop();
		if(a->right){
			s.push(a->right);
		}
		if(a->left){
			s.push(a->left);
		}

	}
}


int main(){
	binaryTree* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->left->left->left = newNode(8);
	// preorderTraversal(root);
	// cout<<endl;
	preorderTraversalWithoutRecursion(root);
	cout<<endl;

}