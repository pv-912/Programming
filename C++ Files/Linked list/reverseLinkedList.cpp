#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
};

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


int getCount(struct ListNode* head)
{
    int count = 0;  // Initialize count
    struct ListNode* current = head;  // Initialize current
    while (current != NULL){
        count++;
        current = current->next;
    }
    return count;
}

void reverseList(ListNode** head_ref){

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
	cout<<sizeOfLinkedList(head)<<endl;
	cout<<getCount(head)<<endl;

	reverseList(&head);
	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}