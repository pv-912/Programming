
/* not completed yet  */

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

bool leafTraversalCheck(binaryTree* root, binaryTree* root1){
	if(root == NULL || root1 ==NULL){
		return false;
	}
	stack<binaryTree*> s;
	stack<binaryTree*> s1;
	s.push(root);
	s1.push(root1);

	while(!s.empty() || !s1.empty()){

		if(s.empty() || s1.empty())
			return false;

		binaryTree* a = s.top();
		while(!a){
			if(a->right){
				s.push(a->right);
			}
			if(a->left){
				s.push(a->left);
			}
			a = s.top();
			s.pop();
		}

		binaryTree* a1 = s1.top();
		while(!a1){
			if(a1->right){
				s1.push(a1->right);
			}
			if(a1->left){
				s1.push(a1->left);
			}
			a1 = s1.top();
			s1.pop();
		}
		
		if (a!=NULL && a1!=NULL)
            return false;
         if (a!=NULL && a1==NULL)
            return false;

        if (a!=NULL && a1!=NULL){
            if (a->data != a1->data)
               return false;
        }
	}
	return true;
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
	// preorderTraversal(root);
	// cout<<endl;
	binaryTree* root1 = newNode(1);
	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);
	root1->right->left = newNode(6);
	root1->right->right = newNode(7);
	root1->left->left->left = newNode(8);
	cout<<leafTraversalCheck(root,root1);
	cout<<endl;

}