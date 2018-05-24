#include <iostream>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNode* newNode(int val){
	TreeNode* root = (struct TreeNode*)malloc(sizeof(TreeNode));
	root->val = val;
	root->right = NULL;
	root->left = NULL;
	return root;
}


TreeNode* insert(TreeNode* root, int val){
	if(root==NULL){
		return newNode(val);
	}

	if(val < root->val)
		root->left = insert(root->left, val);
	if(val > root->val)
		root->right = insert(root->right, val);

	return root;
}
void inorder(TreeNode* root){
	if(root != NULL){
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}

TreeNode* searchNode(TreeNode* root, int valTosearch){
	if (!root || root->val == valTosearch)
		return root;

	if(valTosearch < root->val)
		return searchNode(root->left, valTosearch);
	if(valTosearch > root->val)
		return searchNode(root->right, valTosearch);

}


TreeNode* findMin(TreeNode* root){
	if(root==NULL)
		return NULL;

	TreeNode* temp = root;

	while(temp->left!=NULL){
		temp = temp->left;
	}
	return temp;

}

TreeNode* deleteNode(TreeNode* root, int valToDelete){
	if(root==NULL)
		return NULL;

	if( valToDelete < root->val)
		root->left = deleteNode(root->left, valToDelete);
	else if(valToDelete > root->val)
		root->right = deleteNode(root->right, valToDelete);

	else{
		if(root->left == NULL){
			TreeNode* a = root->right;
			free(root);
			return a;
		}
		else if(root->right == NULL){
			TreeNode* a = root->left;
			free(root);
			return a;
		}

		TreeNode* a = findMin(root);
		root->val = a->val;
		a->right = deleteNode(root->right, a->val);
	}

	return root;
}

TreeNode* sortedArrayToBSTUtil(vector<int> a, int start, int end){
    if(start > end)  
          return NULL;
    int mid = end- (end-start)/2;
    TreeNode* temp = new TreeNode(a[mid]);
    temp->left = sortedArrayToBSTUtil(a, start, mid-1);
    temp->right = sortedArrayToBSTUtil(a, mid + 1, end);
    return temp;
}
TreeNode* sortedArrayToBST(vector<int> &a){
    int size = a.size();
    TreeNode* res = sortedArrayToBSTUtil(a, 0, size-1);
    return res;
}

int findNode(vector<int> a, int toFind){
    
    int i;
    for(int i = 0; i<a.size(); i++){
        if(a[i]== toFind)
            return i;
    }
    return -1;
}

TreeNode* preorderInorderToBSTUtil(const vector<int> &preOrder,const vector<int> &inOrder, int start, int end, int& preIndex){
    if(start>end){
        return NULL;
    }
    int rootKey = findNode(inOrder, preOrder[preIndex]);
    preIndex++;
    TreeNode* root = new TreeNode(inOrder[rootKey]);
    if(start == end)
        return root;
    root->left = preorderInorderToBSTUtil(preOrder, inOrder, start, rootKey-1, preIndex);
    root->right  = preorderInorderToBSTUtil(preOrder, inOrder, rootKey + 1 , end, preIndex);
    return root;
}

TreeNode* preorderInorderToBST(const vector<int> &preOrder,const vector<int> &inOrder){
    int preIndex = 0;
    return preorderInorderToBSTUtil(preOrder, inOrder, 0 , preOrder.size()-1,preIndex);
}

int main(){
	TreeNode* root =  NULL;
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