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

void printLevelLineByLine2Queue(binaryTree* root){
	if(!root){
		return;
	}

	queue<binaryTree*> q1;
	queue<binaryTree*> q2;
	q1.push(root);
	while(!q1.empty() || !q2.empty()){
		while(!q1.empty()){
			if(q1.front()->left != NULL)
				q2.push(q1.front()->left);
			if(q1.front()->right!= NULL)
				q2.push(q1.front()->right);
			cout<<q1.front()->data<<" ";
			q1.pop();

		}
		cout<<endl;
		while(!q2.empty()){
			if(q2.front()->left!= NULL)
				q1.push(q2.front()->left);
			if(q2.front()->right!= NULL)
				q1.push(q2.front()->right);
			cout<<q2.front()->data<<" ";
			q2.pop();
		}
		cout<<endl;
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
	printLevelLineByLine2Queue(root);
	cout<<endl;
	
}
