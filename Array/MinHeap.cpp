#include<iostream>
using namespace std;

//swaps content given two memory locations
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

class MinHeap {
	int *heap_arr;
	int capacity, heap_size;
public:
	//constructor
	MinHeap(int capacity) {
		heap_size = 0;
		capacity = capacity;
		heap_arr = new int[capacity];
	}
	int parent(int i) { return (i - 2) / 2; }
	int left(int i) { return (2*i + 1); }
	int right(int i) { return (2*i + 2); }

	void insertKey(int k) {
		if (heap_size == capacity) {
			return; cout << "Cannot insert\n";
		}
		//we insert at the end in the beginning
		heap_size++;
		int i = heap_size - 1;
		heap_arr[i] = k;
		while (heap_size != 1 && heap_arr[parent(i)] > heap_arr[i]) {
			swap(&heap_arr[i], &heap_arr[parent(i)]);
			i = parent(i);
		}
	}

	//a function to heapify one subtree with a given root, assuming all other subtrees are heapified
	void MinHeapify(int root) {
		int left = left(root);
		int right = right(root);
		int smallest = root;
		if (heap_size > left && heap_arr[left] < heap_arr[root])
			smallest = left;
		if (heap_size > right && heap_arr[right] < heap_arr[smallest])
			smallest = right;
		if (smallest != root) {
			swap(&heap_arr[smallest], &heap_arr[root]);
			MinHeapify(smallest);
		}
	}

	int extractMin() {
		if (heap_size <= 0)
			return INT_MAX;
		if (heap_size == 1) {
			heap_size--; return heap_arr[0];
		}
		int root = heap_arr[0];
		heap_arr[0] = heap_arr[heap_size - 1];
		heap_size--;
		
	}
};

int main() {
	int x = 5, y = 6;
	printf("%d, %d\n", x, y);
	swap(&x, &y);
	printf("%d, %d\n", x, y);

	MinHeap h(11);
	h.insertKey(3); 
    h.insertKey(2); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45);
}