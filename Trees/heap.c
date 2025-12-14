#include<stdio.h>
#include<stdlib.h>

typedef struct maxHeap {
    int *arr;
    int size;
    int capacity;
} maxHeap;

maxHeap *createHeap(int capacity) {
    maxHeap *heap = (maxHeap *) malloc (sizeof(maxHeap));
    heap -> capacity = capacity;
    heap -> size = 0;
    heap -> arr = (int *) malloc (capacity * sizeof(int));
    return heap;
}

int parent(int index) {
    return (index - 1) / 2;
}

int rightChild(int index) {
    return 2 * index + 2;
}

int leftChild(int index) {
    return 2 * index + 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(maxHeap *heap, int index) {
    while(index > 0 && heap -> arr[parent(index)] < heap -> arr[index]) {
        swap(&heap -> arr[parent(index)], &heap -> arr[index]);
        index = parent(index);
    }
}

void heapifyDown(maxHeap *heap, int index) {
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);
    if(left < heap -> size && heap -> arr[left] > heap -> arr[largest]) {
        largest = left;
    }

    if(right < heap -> size && heap -> arr[right] > heap -> arr[largest]) {
        largest = right;
    }

    if(largest != index) {
        swap(&heap -> arr[index], &heap -> arr[largest]);
        heapifyDown(heap, largest);
    }
}

void insert(maxHeap *heap, int value) {
    if(heap -> size == heap -> capacity) {
        printf("The heap is full. Cannot insert the value\n");
        return;
    }
    heap -> arr[heap -> size] = value;
    heap -> size++;
    heapifyUp(heap, heap -> size - 1);
}

int delete(maxHeap *heap) {
    if(heap -> size == 0) {
        printf("The heap is empty. Cannot delete element.\n");
        return -1;
    }
    int root = heap -> arr[0];
    heap -> arr[0] = heap -> arr[heap -> size - 1];
    heap -> size--;
    heapifyDown(heap, 0);
    return root;
}

void display(maxHeap *heap) {
    for(int i = 0; i < heap -> size; i++) {
        printf("%d ", heap -> arr[i]);
    }
    printf("\n");
}

int main() {
    maxHeap *heap = createHeap(10);
    insert(heap, 10);
    insert(heap, 20);
    insert(heap, 5);
    insert(heap, 15);
    insert(heap, 30);

    printf("Heap after insertion is: ");
    display(heap);

    printf("Deleted root: %d\n", delete(heap));
    printf("Heap after deletion: ");
    display(heap);
}