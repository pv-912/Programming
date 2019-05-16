#include <iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};

void printList(node *a){
    while(a != NULL){
        cout<<a->data<<" ";
        a = a -> next;
    }
    cout<<endl;
}

void pushHead(struct node** headRef, int newData){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = (*headRef);
	(*headRef) = newNode;
} 

void pushBetween(struct node* prevNode, int newData){
	if(prevNode == NULL){
		cout<<"Given node is empty;"<<endl;
		return;
	}
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = newData;
	newNode->next = prevNode->next;
	prevNode->next = newNode;
}

void pushLast(struct node** headRef, int newData){
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	struct node *last = *headRef;
	newNode->data = newData;
	newNode->next = NULL;
	if(*headRef == NULL){
		*headRef == newNode;
		return;
	}

	while(last->next!=NULL){
		last = last->next;
	}
	last->next = newNode;
	return;
}

void deleteNode(struct node** headRef, int key){
	struct node* temp = *headRef, *prev;

	if(temp!=NULL && temp->data==key){
		*headRef = temp->next;
		free(temp);
		return; 
	} 

	while(temp!=NULL && temp->data!=key){
		prev = temp;
		temp = temp->next;
	}
	prev->next = temp->next;
	free(temp);
}

void deleteNodeAtGivenPosition(struct node** headRef, int position){
	struct node* temp = *headRef;

	if(*headRef==NULL){
		return;
	}


	if(position==0){
		*headRef = temp->next;
		free(temp);
		return;
	}

	for(int i=0;temp!=0 && i<position-1; i++){
		temp = temp->next;
	}

	if(temp==0 || temp->next==0){
			return;
	}
	// struct node *next = temp->next->next;
	free(temp->next);
	temp->next = temp->next->next;
}

void listLength(struct node** headRef){
	struct node* temp = *headRef;
	int a = 0;
	while(temp!=NULL){
		temp = temp->next;
		a++;
	}
	cout<<a<<endl;
}

int listLengthRecursive(struct node* head){
	if(head==NULL){
		return 0;
	}

	return 1 + listLengthRecursive(head->next);
}

bool search(struct node* head,int key){
	while(head!=NULL){
		if(head->data==key){
			return true;
		}
		head = head->next;
	}

	return false;
}

void swapNodes(struct node** head, int key1, int key2){
	if(key1==key2){
		return;
	}
	
	struct node* temp1 = *head;
	struct node* temp2 = *head;

	while(temp1!=NULL && temp1->data!=key1){
		temp1 = temp1->next;
	}

	while(temp2!=NULL && temp2->data!=key2){
		temp2 = temp2->next;
	}
	if(temp1==NULL || temp2==NULL){
		cout<<"given Key is not present"<<endl;
		return;
	}

	int temp = temp1->data;
	temp1->data = temp2->data;
	temp2->data = temp;

	printList(*head);
}

void getNodeValue(struct node** headRef, int index){
	struct node* temp = *headRef;
	for(int i=0; i<index; i++){
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}

int main() {
	struct node* first = NULL;
	struct node* second =NULL;
	struct node* third = NULL;
	
	first = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	
	first->data = 1;
	first->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next  = NULL;
	
	pushHead(&first, 5);
	pushBetween(second, 6);
	pushLast(&first,9);

	listLength(&first);
	int length = listLengthRecursive(first);
	cout<<length<<endl;
	getNodeValue(&first,5);
	search(first, 3) ? cout<<"yes"<<endl : cout<<"NO"<<endl;
	search(first, 30) ? cout<<"yes"<<endl : cout<<"NO"<<endl;
	printList(first);
	swapNodes(&first,1,20);

	deleteNode(&first, 3);
	printList(first);

	deleteNodeAtGivenPosition(&first, 1);
	deleteNodeAtGivenPosition(&first, 3);
	printList(first);
	return 0;

}
