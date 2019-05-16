#include <iostream>

using namespace std;

struct binarySearchTree{
	int data;
	binarySearchTree* left;
	binarySearchTree* right;
};

struct binarySearchTree* newNode(int data){
	binarySearchTree* root = (struct binarySearchTree*)malloc(sizeof(binarySearchTree));
	root->data = data;
	root->right = NULL;
	root->left = NULL;
	return root;
}


binarySearchTree* insert(binarySearchTree* root, int data){
	if(root==NULL){
		return newNode(data);
	}

	if(data < root->data)
		root->left = insert(root->left, data);
	if(data > root->data)
		root->right = insert(root->right, data);

	return root;
}
void inorder(binarySearchTree* root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

binarySearchTree* BSTtoGreaterSumTreeUtil(binarySearchTree* root, int* sum){
	if(root==NULL)
		return NULL;
	root->right = BSTtoGreaterSumTreeUtil(root->right, sum);
	int temp = *sum;
	*sum = *sum + root->data;
	root->data = temp;
	root -> left = BSTtoGreaterSumTreeUtil(root->left, sum);
	return root;
}	

binarySearchTree* BSTtoGreaterSumTree(binarySearchTree* root){
	int sum=0;
	BSTtoGreaterSumTreeUtil(root, &sum);
}

int main(){
	binarySearchTree* root =  NULL;
	root = insert(root, 11);
	insert(root, 2);
	insert(root, 29);
	insert(root, 1);
	insert(root, 15);
	insert(root, 7);
	insert(root, 40);
	insert(root, 35);
	inorder(root);
	cout<<endl;
	binarySearchTree* a =  BSTtoGreaterSumTree(root);
	inorder(a);

}