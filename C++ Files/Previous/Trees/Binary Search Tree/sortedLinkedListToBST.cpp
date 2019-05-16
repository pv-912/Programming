#include <iostream>

using namespace std;

struct ListNode{
	int data;
	ListNode* next;
};

void pushHead(struct ListNode** head_ref, int dataToInsert){
	struct ListNode *newNode = new ListNode();
	newNode->data = dataToInsert;
	newNode->next = *head_ref;
	*head_ref = newNode;
}

void printList(struct ListNode *node){
	ListNode* temp = node;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        cout<<endl;
    }
}

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
	else
		return;
}

int countNodesLinkedList(ListNode* head_ref){
	ListNode* temp = head_ref;
	int count =0;
	while(temp!=NULL){
		temp = temp->next;
		count++;
	}
	return count;
}

binarySearchTree* linkedListToBSTUtil(ListNode** head_ref, int n){
	if(n <= 0)
		return NULL;

	binarySearchTree* left = linkedListToBSTUtil(head_ref, n/2);

	binarySearchTree* root = newNode((*head_ref)->data);
	root->left = left;
	*head_ref = (*head_ref)->next;

	root->right = linkedListToBSTUtil(head_ref, n-n/2-1);

	return root;
}

binarySearchTree* linkedListToBST(ListNode* head_ref){
	int n = countNodesLinkedList(head_ref);
	return linkedListToBSTUtil(&head_ref, n);
}

int main(){
	struct ListNode* head = NULL;
    pushHead(&head, 7);
    pushHead(&head, 6);
    pushHead(&head, 5);
    pushHead(&head, 4);
    pushHead(&head, 3);
    pushHead(&head, 2);
    pushHead(&head, 1);
    printList(head);
    binarySearchTree* root =  linkedListToBST(head);
    inorder(root);
}