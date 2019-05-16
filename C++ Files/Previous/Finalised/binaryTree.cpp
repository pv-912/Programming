#include <iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data){
	struct node* nNode = new node();
	nNode->data = data;
	nNode->left = NULL;
	nNode->right = NULL;
	return nNode;
}

int height(struct node* root){
	if(root == NULL){
		return 0;
	}

	int lheight = height(root->left);
	int rheight = height(root->right);

	if(lheight > rheight){
		return lheight + 1;
	}else{
		return rheight + 1;
	}
}

void printGivenLevel(struct node* root, int level){
	if(root==NULL){
		return;
	}
	if(level==1){
		cout<<root->data<<" ";
	}else if(level>1){
		printGivenLevel(root->left,level-1);
		printGivenLevel(root->right,level-1);
	}
}

void levelOrderTraversal(struct node* root){
	if(root==NULL){
		return;
	}

	for(int i=0; i<=height(root); i++){
		printGivenLevel(root,i);
	}
}

void levelOrderTraversalUsingQueue(struct node* root){
	if(root==NULL){
		return;
	}
	queue<node*> Q;
	Q.push(root);
	while(!Q.empty()){
		struct node* current = Q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL){Q.push(current->left);}
		if(current->right!=NULL){Q.push(current->right);}
		Q.pop();
	}

}

int main() {
	struct node* root = NULL;
	root = newNode(5);
	root->left = newNode(8);
	root->right = newNode(10);
	root->left->left = newNode(9);
	int a = height(root);
	cout<<"Height of tree is : "<<a<<endl;
	levelOrderTraversal(root);
	levelOrderTraversalUsingQueue(root);
	return 0;

}
