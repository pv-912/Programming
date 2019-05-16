#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct Queue{
	int front, rear, size;
	unsigned capacity;
	int* array;
};

struct Queue* createQueue(unsigned capacity){
	struct Queue* newQueue = new Queue();
	newQueue->capacity = capacity;
	newQueue->front = newQueue->size = 0;
	newQueue->rear = capacity - 1;
	newQueue->array = (int*)malloc(newQueue->capacity * sizeof(int));
	return newQueue;
}

int isFull(struct Queue* queue){
	return (queue->capacity == queue->size);
}

int isEmpty(struct Queue* queue){
	return (queue->size == 0);
}

void enqueue(struct Queue* queue, int data){
	if(isFull(queue)){
		return;
	}
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = data;
	queue->size = queue->size + 1;
	cout<<"enqueued "<<data<<endl;
}

int dequeue(struct Queue* queue){
	if(isEmpty(queue)){
		return INT_MIN;
	}
	int data = queue->array[queue->front];
	queue->front = (queue->front + 1)% queue->capacity;
	queue->size = queue->size -1;
	return data;
}

int front(struct Queue* queue){
	if(isEmpty(queue)){
		return INT_MIN;	
	} 
	return queue->array[queue->front];
}

int rear(struct Queue* queue){
	if(isFull(queue)){
		return INT_MIN;	
	}
	return queue->array[queue->rear];
}

int main() {
	struct Queue* queue = createQueue(110);
	enqueue(queue, 5);
	enqueue(queue, 52);
	enqueue(queue, 57);
	enqueue(queue, 56);
	cout<<"dequeued "<<dequeue(queue)<<endl;
	cout<<"front "<<front(queue)<<endl;
	cout<<"rear "<<rear(queue)<<endl;
	return 0;
}
