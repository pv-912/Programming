#include <iostream>
#include <stack>
#include <climits>
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

binarySearchTree* searchNode(binarySearchTree* root, int dataTosearch){
	if (!root || root->data == dataTosearch)
		return root;

	if(dataTosearch < root->data)
		return searchNode(root->left, dataTosearch);
	if(dataTosearch > root->data)
		return searchNode(root->right, dataTosearch);

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

binarySearchTree* ConstructBSTTree(int pre[], int *preIndex, int low, int high, int size){
	if(low> high || *preIndex >= size){
		return NULL;
	}

	binarySearchTree* root = newNode(pre[*preIndex]);
	*preIndex = *preIndex +1 ;
	if(low == high){
		return root;
	}
	int i;
	for(i = low; i<=high; i++)
		if(root->data < pre[i])
			break;

	root->left = ConstructBSTTree(pre, preIndex, *preIndex, i-1, size);	
	root->right = ConstructBSTTree(pre, preIndex, i, high, size);	
	return root;
}

binarySearchTree* ConstructBST(int pre[], int size){
	int preIndex = 0;
	return ConstructBSTTree(pre, &preIndex, 0, size -1, size);
}

//second method

binarySearchTree* ConstructBSTTree2(int pre[], int* preIndex, int key, int min, int max, int size){
	if(min>max || *preIndex >= size){
		return NULL;
	}

	binarySearchTree* root = NULL;

	if(key>min && key < max){
			root = newNode(key);
			*preIndex = *preIndex +1;
		if(*preIndex<size){
			root->left = ConstructBSTTree2(pre, preIndex, pre[*preIndex], min, key, size ); 
			root->right = ConstructBSTTree2(pre, preIndex, pre[*preIndex], key, max, size); 
		}
	}
	return root;
}

binarySearchTree* ConstructBST2(int pre[], int size){
	int preIndex = 0;
	return ConstructBSTTree2(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
}

// using stack

binarySearchTree* ConstructBSTTreeUsingStack(int pre[],  int size){
	
	stack<binarySearchTree*> s;
	binarySearchTree* root = newNode(pre[0]);
	s.push(root);
	for(int i=1; i<size; i++){
		binarySearchTree* a = NULL; 		
		while(!s.empty() && s.top()->data<pre[i]){
			a = s.top();
			s.pop();
		}

			if(a!=NULL){
				a->right = newNode(pre[i]);
				s.push(a->right);
			}
			else{
				s.top()->left = newNode(pre[i]);
				s.push(s.top()->left);
			}
	}
	return root;
}



int main(){
	int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );
 
    struct binarySearchTree *root = ConstructBST(pre, size);
    inorder(root);
    cout<<endl;
    struct binarySearchTree *root1 = ConstructBST2(pre, size);
    inorder(root1);
    cout<<endl;
    struct binarySearchTree *root2 = ConstructBSTTreeUsingStack(pre, size);
    inorder(root2);
}