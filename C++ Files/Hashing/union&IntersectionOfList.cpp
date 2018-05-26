#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

struct Node{
	int data;
	Node* next;
};



void push (struct Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList (struct Node *node){
    while (node != NULL){
        printf ("%d ", node->data);
        node = node->next;
    }
}
Node* getIntersection(Node* root1, Node* root2){
	unordered_set<int > m ;
	Node* head1 = root1;
	Node* head2 = root2;
	while(head1){
		m.insert(head1->data);
		head1 = head1->next;
	}

	while(head2){
		if(m.find(head2->data) != m.end()){
			head2 = head2->next;
		}
		else{
			m.insert(head2->data);
			head2 = head2->next;
		}
	}
	Node* a = NULL;
	for(auto it = m.begin(); it!=m.end(); it++){
		push(&a,*it);
	}
	return a;
}

Node* getUnion(Node* root1, Node* root2){
	unordered_set<int> m;
	Node* head1 = root1;
	Node* head2 = root2;

	Node* a = NULL;
	while(head1){
		m.insert(head1->data);
		head1 = head1->next;
	}
	while(head2){
		if(m.find(head2->data) != m.end()){
			push(&a,head2->data);
		}
			head2 = head2->next;
	}
	return a;
}

int main(){
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* intersecn = NULL;
    struct Node* unin = NULL;
 
    push (&head1, 20);
    push (&head1, 4);
    push (&head1, 15);
    push (&head1, 10);
 
    push (&head2, 10);
    push (&head2, 2);
    push (&head2, 4);
    push (&head2, 8);
 
    intersecn = getIntersection(head1, head2);
    unin = getUnion (head1, head2);
 
    printf ("\n First list is \n");
    printList (head1);
 
    printf ("\n Second list is \n");
    printList (head2);
 
    printf ("\n Intersection list is \n");
    printList (intersecn);
 
    printf ("\n Union list is \n");
    printList (unin);
 
    return 0;
}
