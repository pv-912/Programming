
/* not completed yet */

/* 
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
*/
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* a, int b, int c) {

}

int main(){
	ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
	head->val = 1;
	head->next = NULL;
	pushLast(&head,2);
	pushLast(&head,3);
	pushLast(&head,4);
	pushLast(&head,5);
	pushLast(&head,6);
	reverseBetween(head,2,4);
	cout<<endl;

	while(head != NULL){
		cout<<head->val<<" ";
		head = head->next;
	}
	cout<<endl;
	return 0;
}