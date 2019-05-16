#include <iostream>
#include <climits>
using namespace std;

struct minHeap{
	int* arr;
	int capacity;
	int heap_size;
	public:
		minHeap(int x);
		void minHeapify(int x);
		int parent(int i){return (i-1)/2;}
		int left(int i){return (2*i+1);}
		int right(int i){return (2*i+2);}
		int extractMin();
		void decreaseKey(int i, int minVal);
		int getMin(){return arr[0];}
		void deleteKey(int i);
		void insertKey(int x);	
};

minHeap::minHeap(int x){
	heap_size = 0;
	capacity = x;
	arr = new int[x];
}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void minHeap::insertKey(int x){
	if(heap_size == capacity){
		cout<<"heap full"<<endl;
		return;
	}
	heap_size++;
	int i = heap_size - 1;
	arr[i] = x;

	while(i!=0 && arr[parent(i)] > arr[i]){
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

void minHeap::decreaseKey(int i, int minVal){
	arr[i] = minVal;

	while(i!=0 && arr[parent(i)] > arr[i]){
		swap(&arr[parent(i)], &arr[i]);
		i = parent(i);
	}
}

int minHeap::extractMin(){
	if(heap_size <= 0){
		return INT_MAX;
	}

	if(heap_size == 1){
		heap_size--;
		return arr[0];
	}

	int temp = arr[0]; 
	arr[0] = arr[heap_size-1];
	heap_size--;
	minHeapify(0);
	return temp;
}

void minHeap::deleteKey(int i){
	decreaseKey(i, INT_MIN);
	extractMin();
}

void minHeap::minHeapify(int i){
	int l = left(i);
	int r = right(i);
	int smallest = i;

	if(l<heap_size && arr[l] < arr[smallest])
		smallest = l;
	if(r<heap_size && arr[r] < arr[smallest])
		smallest = r;

	if(smallest!=i){
		swap(&arr[i], &arr[smallest]);
		minHeapify(smallest);
	}
}

int main(){
	minHeap h(11);
	h.insertKey(3);
    h.insertKey(2);
    h.deleteKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);
    cout << h.extractMin() << " ";
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}