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

binarySearchTree* sortedArrayToBST(int arr[], int low, int high){
	if(low>high)
		return NULL;

	int mid = (high +low)/2;
	binarySearchTree* root = newNode(arr[mid]);

	root->left = sortedArrayToBST(arr, low, mid-1);
	root->right = sortedArrayToBST(arr, mid+1, high);
	return root;
}

int main(){
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    binarySearchTree* root = sortedArrayToBST(arr, 0, n-1);
    inorder(root);
 
    return 0;
}