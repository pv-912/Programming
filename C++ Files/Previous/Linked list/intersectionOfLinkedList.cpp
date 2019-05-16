#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode *next;
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

ListNode* getIntersectionListNode(ListNode* A, ListNode* B) {
    ListNode *ptr;
    ptr=A;
    int len1=0;

    while(ptr!=NULL){
        ptr=ptr->next;
        len1++;
    }

    ptr=B;
    int len2=0;

    while(ptr!=NULL){
        ptr=ptr->next;
        len2++;
    }

    if(len1>len2){ 
        while(len1>len2){
            ptr=A;
            A=A->next;
            free(ptr);
            len1--;
        }
    }

    if(len2>len1){   
        while(len2>len1){
            ptr=B;
            B=B->next;
            free(ptr);
            len2--;
        }
    }

    ListNode *p1,*p2;
    p1=A;
    p2=B;
    while(p1!=p2){
        p1=p1->next;
        p2=p2->next;
    }
    
    return p1;
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

	ListNode* head1 = new ListNode();
	head1->val = 11;
	head1->next = NULL;
	pushLast(&head1,4);
	pushLast(&head1,5);
	pushLast(&head1,6);


	// while(head != NULL){
	// 	cout<<head->val<<" ";
	// 	head = head->next;
	// }
	// cout<<endl;
	// while(head1 != NULL){
	// 	cout<<head1->val<<" ";
	// 	head1 = head1->next;
	// }
	// cout<<endl;
	ListNode* soln = getIntersectionListNode(head, head1);
	cout<<soln<<endl;
	while(soln != NULL){
		cout<<soln<<" ";
		soln = soln->next;
	}
	return 0;
}