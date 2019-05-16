#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
};

void pushHead(struct ListNode** head_ref, int valToInsert){
	struct ListNode *newListNode = new ListNode();
	newListNode->val = valToInsert;
	newListNode->next = *head_ref;
	*head_ref = newListNode;
}

void pushLast(struct ListNode** head_ref, int valToInsert){
	struct ListNode *newListNode = new ListNode();
	newListNode->val = valToInsert;
	newListNode->next = NULL;
	struct ListNode *last = *head_ref;

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

void pushMiddle(struct ListNode** head_ref, int valToInsert, int position){
	struct ListNode* newListNode = new ListNode();
	newListNode->val = valToInsert;

	struct ListNode *position_ref = *head_ref;

	if(*head_ref == NULL){
		cout<<"list is empty";
		return;
	}

	for(int i=0; i<position; i++){
		position_ref = position_ref->next;
	}

	newListNode->next = position_ref->next;
	position_ref->next = newListNode;
}

void deleteListNode(struct ListNode** head_ref, int valToDelete){
	struct ListNode *position_ref = *head_ref, *prev;

	if(position_ref!=NULL && position_ref->val == valToDelete ){
		*head_ref = position_ref->next;
		free(position_ref);
		return;
	}

	while(position_ref!=NULL && position_ref->val != valToDelete ){
		prev = position_ref;
		position_ref = position_ref->next;
	}

	if(position_ref == NULL){
		cout<<"val not present";
		return;
	}

	prev->next = position_ref->next;
	free(position_ref);
}



void middleElement(struct ListNode** head_ref){
	struct ListNode* one = *head_ref;
	struct ListNode* two = *head_ref;

	while(two != NULL){
		one = one->next;
		two = two->next->next;
	}

	cout<<endl<<one->val<<endl;
}

void printList(struct ListNode *ListNode){
	ListNode* temp = ListNode;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void deleteDuplicates(ListNode* A) {
   if(!A)
       return;
   ListNode* prev = A;
   ListNode* cur = A->next;
   ListNode* temp;
   while(cur){
       if(cur->val == prev->val){
       		prev->next = cur->next;
           cur->next = NULL;
           delete cur;
           cur = prev->next;
       }
       else{
           prev = cur;
           cur = cur->next;
       }
       
   }
   // return A;
   ListNode* temp1 = A;
    while(temp1!=NULL){
        cout<<temp1->val<<" ";
        temp1 = temp1->next;
    }
    cout<<endl;
}

int main(){
	struct ListNode* head = new ListNode();
	struct ListNode* second = new ListNode();
	struct ListNode* third = new ListNode();

	head->val = 1;
	head->next = second;

	second->val = 1;
	second->next = third;

	third->val = 3;
	third->next = NULL;

	pushMiddle(&head,10,2);
	pushLast(&head,3);
	pushLast(&head,3);
	pushLast(&head,3);
	printList(head);

	deleteDuplicates(head);
	// deleteListNode(&head,20);
	// middleElement(&head);	
	// printList(head);
	return 0;
}