#include <iostream>
using namespace std;

struct node{
	int data;
	struct node* next;
};

struct Queue{
	struct node *front, *rear;
};

struct node* newNode(int data){
	struct node* nNode = new node();
	nNode->data = data;
	nNode->next = NULL;
	return nNode;
}

struct Queue* newQueue(){
	struct Queue* queue = new Queue();
	queue->front = queue->rear = NULL;
	return queue; 
}

void enqueue(struct Queue* queue, int data){
	struct node* temp = newNode(data);

	if(queue->rear == NULL){
		queue->front = queue->rear = temp;
		cout<<" enqueued "<<data<<endl;
		return;
	}
	queue->rear->next = temp;
	queue->rear = temp;
	cout<<" enqueued "<<data<<endl;
}

int dequeue(struct Queue* queue){
	if(queue->front==NULL){
		return 0;
	}
	int data = queue->front->data;
	queue->front = queue->front->next;

	if(queue->front == NULL){
		queue->rear == NULL;
	}
	return data;
}

int main() {
	struct Queue* queue = newQueue();
	enqueue(queue, 5);
	enqueue(queue, 52);
	enqueue(queue, 57);
	enqueue(queue, 56);
	cout<<"dequeued "<<dequeue(queue)<<endl;
	return 0;
}
