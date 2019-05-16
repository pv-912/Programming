#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct binaryTree{
	int data;
	binaryTree* left;
	binaryTree* right;
};

binaryTree* newNode( int data){
	binaryTree* a = (struct binaryTree*)malloc(sizeof(struct binaryTree));
	a->data = data;
	a->left = NULL;
	a->right = NULL;
	return a;	
}

int height(binaryTree* root){
	if(root == NULL){
		return 0;
	}

	return max(height(root->left), height(root->right)) + 1;
}

void printLevelOrderTranversal(binaryTree* root){
	if(root == NULL){
		return;
	}
	queue<binaryTree*> q;
	q.push(root);
	
	while(!q.empty()){
		binaryTree* a = q.front();
		cout<<a->data<<" ";
		if(a->left != NULL)
			q.push(a->left);
		if(a->right != NULL)
			q.push(a->right);
		q.pop();
	}

	return;
}

void printGivenLevel(binaryTree* root, int level){
	if(root == NULL){
		return;
	}
	if(level == 1){
		cout<<root->data<<" ";
	}
	else if(level > 1 ){
		printGivenLevel(root->left , level-1);
		printGivenLevel(root->right, level-1);
	}
}

void printLevelOrderTranversalLineByLine(binaryTree* root){
	if(root ==NULL){
		return;
	}
	int h = height(root);
	for(int i=0; i<=h; ++i){
		printGivenLevel(root, i);
		cout<<endl;
	}
}

void reverseLevelOrder(binaryTree* root){
	if(root == NULL){
		return;
	}
	int h = height(root);
	for(int i=h; i>=0; i--){
		printGivenLevel(root, i);
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
	cout<<height(root)<<endl;
	printLevelOrderTranversal(root);
	cout<<endl;
	printGivenLevel(root,3);
	printLevelOrderTranversalLineByLine(root);
	cout<<endl;
	reverseLevelOrder(root);
}
