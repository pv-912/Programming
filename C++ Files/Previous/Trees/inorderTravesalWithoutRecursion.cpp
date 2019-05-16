
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
void inorderTraversal(binaryTree* root){
	if(root == NULL){
		return;
	}

	inorderTraversal(root->left);
	cout<<root->data<<" ";
	inorderTraversal(root->right);
}

void inorderTraversalWithoutRecursion(binaryTree* root){
	if(root == NULL){
		return;
	}
	binaryTree* a = root;
	stack<binaryTree*> s;
	bool done = 0;
	while(!done){
		if(a != NULL){
			s.push(a);
			a = a->left;
		}
		else{
			if(!s.empty()){
				a = s.top();
				s.pop();
				cout<<a->data<<" ";
				a = a->right;
			}
			else{
				done = 1;
			}
		}
	}
}

void inorderTraversalWithoutRecursionWithoutStack(binaryTree* root){

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
	inorderTraversal(root);
	cout<<endl;
	inorderTraversalWithoutRecursion(root);
	cout<<endl;
	inorderTraversalWithoutRecursionWithoutStack(root);

}