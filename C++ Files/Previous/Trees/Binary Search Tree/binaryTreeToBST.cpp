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

void inorder(binarySearchTree* root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

void storeInorder(int arr[], int *preIndex, binarySearchTree* root){
	if(root==NULL)
		return;

	storeInorder(arr, preIndex, root->left);
	arr[*preIndex] = root->data;
	(*preIndex)++;
	storeInorder(arr, preIndex, root->right);
}

int countNodes(binarySearchTree* root){
	if(root==NULL)
		return 0;
	return countNodes(root->left) + countNodes(root->right) + 1;
}

int compare(const void *a, const void *b){
	return (*(int *)a - *(int *)b);
}

void arrToBST(int *arr, int *preIndex, binarySearchTree* root){
	if(root==NULL)
		return;

	arrToBST(arr, preIndex, root->left);
	root->data = arr[*preIndex];
	(*preIndex)++;

	arrToBST(arr, preIndex, root->right);
}

void binaryTreeToBST(binarySearchTree* root){
	if(root==NULL)
		return;
	int nodes = countNodes(root);
	int *arr = new int[nodes];
	int i = 0;
	storeInorder(arr, &i, root);

	qsort(arr, nodes, sizeof(arr[0]), compare);

	i = 0;
	arrToBST(arr, &i , root);
	delete [] arr;
}

int main(){
	struct binarySearchTree *root = NULL;
    root = newNode(10);
    root->left = newNode(30);
    root->right = newNode(15);
    root->left->left = newNode(20);
    root->right->right = newNode(5);
 
    binaryTreeToBST (root);
	inorder(root);
	cout<<endl;
	inorder(root);
}