
/* not complete yet */

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
};

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void pushLast(ListNode** head_ref, int valToInsert){
	ListNode *newListNode = new ListNode();
	newListNode->val = valToInsert;
	newListNode->next = NULL;
	ListNode *last = *head_ref;

	if(*head_ref == NULL){
		*head_ref = newListNode;
		return;
	}
	while(last->next!=NULL){
		last = last->next;
	}

	last->next = newListNode;
	return;
}

void deleteNode(struct ListNode** head_ref, int dataToDelete){
	struct ListNode *position_ref = *head_ref, *prev;

	if(position_ref!=NULL && position_ref->val == dataToDelete ){
		*head_ref = position_ref->next;
		free(position_ref);
		return;
	}

	while(position_ref!=NULL && position_ref->val!= dataToDelete ){
		prev = position_ref;
		position_ref = position_ref->next;
	}

	if(position_ref == NULL){
		cout<<"data not present";
		return;
	}

	prev->next = position_ref->next;
	free(position_ref);
}


int sizeOfLinkedList(ListNode* head_ref){
	int size = 0;
	ListNode *temp = head_ref;
	while(temp!=NULL){
		size++;
		temp = temp->next;
	}
	return size;
}

// int sizeOfLinkedList(ListNode* head){
// 	if(head == NULL)
// 		return 0;

// 	return 1+sizeOfLinkedList(head->next);
// }

void reverseList(ListNode** head_ref){
	int size = sizeOfLinkedList(*head_ref);
	if(size == 0 || size == 1){
		return;
	}

	int x = (*head_ref)->val;
	deleteNode(head_ref, x);
	reverseList(head_ref);
	pushLast(head_ref, x);

}

int main(){
	ListNode* head = new ListNode();
	head->val = 1;
	head->next = NULL;
	pushLast(&head,2);
	pushLast(&head,3);
	pushLast(&head,4);
	pushLast(&head,5);
	pushLast(&head,6);

	

	// while(head != NULL){
	// 	cout<<head->val<<" ";
	// 	head = head->next;
	// }
	// cout<<endl;

	reverseList(&head);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}