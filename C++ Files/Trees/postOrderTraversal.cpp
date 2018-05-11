
/* not completed yet  postOrderTraversalUsing1Stacks() yet to do */

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
void postOrderTraversal(binaryTree* root){
	if(root == NULL){
		return;
	}
	postOrderTraversal(root->left);
	postOrderTraversal(root->right);
	cout<<root->data<<" ";
}

void postOrderTraversalUsing2Stacks(binaryTree* root){
	if(root == NULL){
		return;
	}

	stack<binaryTree*> s;
	stack<binaryTree*> s2;
	s.push(root);
	while(!s.empty()){
		binaryTree* a = s.top();
		s2.push(a);
		s.pop();
		if(a->left){
			s.push(a->left);
		}
		if(a->right){
			s.push(a->right);
		}
	}

	while(!s2.empty()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}	
	
}

void postOrderTraversalUsing1Stacks(binaryTree* root){
	
	if(root == NULL){
		return;
	}
	binaryTree* a = root;
	stack<binaryTree*> s;
	s.push(root);
	// int i =19;
	while(!s.empty()){
		if(a){
			if(a->right){s.push(a->right);}
			s.push(a);
			a = a->left;
		}
		else{
			a  = s.top();
			s.pop();
			if(a->right && a->right == s.top()){
					 
					s.pop();
					s.push(a);
					a =a->right;
			}
			else{
				cout<<a->data<<" ";
				a = NULL;
			}	
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
	// postOrderTraversal(root);
	// cout<<endl;
	// postOrderTraversalUsing2Stacks(root);
	// cout<<endl;
	postOrderTraversalUsing1Stacks(root);
	cout<<endl;

}