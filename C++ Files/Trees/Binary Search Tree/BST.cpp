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

binarySearchTree* searchNode(binarySearchTree* root, int dataTosearch){
	if (!root || root->data == dataTosearch)
		return root;

	if(dataTosearch < root->data)
		return searchNode(root->left, dataTosearch);
	if(dataTosearch > root->data)
		return searchNode(root->right, dataTosearch);

}


binarySearchTree* findMin(binarySearchTree* root){
	if(root==NULL)
		return NULL;

	binarySearchTree* temp = root;

	while(temp->left!=NULL){
		temp = temp->left;
	}
	return temp;

}

binarySearchTree* deleteNode(binarySearchTree* root, int dataToDelete){
	if(root==NULL)
		return NULL;

	if( dataToDelete < root->data)
		root->left = deleteNode(root->left, dataToDelete);
	else if(dataToDelete > root->data)
		root->right = deleteNode(root->right, dataToDelete);

	else{
		if(root->left == NULL){
			binarySearchTree* a = root->right;
			free(root);
			return a;
		}
		else if(root->right == NULL){
			binarySearchTree* a = root->left;
			free(root);
			return a;
		}

		binarySearchTree* a = findMin(root);
		root->data = a->data;
		a->right = deleteNode(root->right, a->data);
	}

	return root;
}

int main(){
	binarySearchTree* root =  NULL;
	root = insert(root, 1);
	insert(root, 3);
	insert(root, 4);
	insert(root, 5);
	insert(root, 6);
	insert(root, 7);
	insert(root, 2);
	inorder(root);
	deleteNode(root,5);
	cout<<endl;
	inorder(root);
}