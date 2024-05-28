#include<iostream>
#include<cstddef>
using namespace std;

class MaxHeap {

public:    
    static void heapifyUp (int* arr, size_t size) {
        int index = size;
        int parentIndex = index/2;

        while(parentIndex >= 1 && arr[parentIndex - 1] < arr[index - 1]) {
            int temp = arr[parentIndex - 1];
            arr[parentIndex - 1] = arr[index - 1];
            arr[index - 1] = temp;

            index = parentIndex;
            parentIndex = index/2;
        }
    }

    static void heapifyDown (int* arr, size_t size) {
        int index = 1;
        int leftChild = index*2 > size ? -1 : index*2;
        int rightChild = index*2 + 1 > size ? -1 : index*2 + 1;

        int greaterChild = -1;

        if (leftChild != -1 && rightChild != -1) {
            if (arr[leftChild - 1] > arr[rightChild - 1]) {
               greaterChild = leftChild;
            } else {
               greaterChild = rightChild;
            }
        } else if( leftChild != -1) {
            greaterChild = leftChild;
        }

        while (greaterChild != -1 && arr[index - 1] < arr[greaterChild - 1]){
            int temp = arr[index - 1];
            arr[index - 1] = arr[greaterChild - 1];
            arr[greaterChild - 1] = temp;

            index = greaterChild;
            greaterChild = -1;

            int leftChild = index*2 > size ? -1 : index*2;
            int rightChild = index*2 + 1 > size ? -1 : index*2 + 1;

            if (leftChild != -1 && rightChild != -1) {
              if (arr[leftChild - 1] > arr[rightChild - 1]) {
                 greaterChild = leftChild;
              } else {
                 greaterChild = rightChild;
              }
            }  else if( leftChild != -1) {
            greaterChild = leftChild;
        }
        }
    }

    static void insertItem (int* arr, size_t size, int item) {
        arr[size] = item;
        heapifyUp(arr,size+1);
    }

    static int deleteItem (int* arr, size_t size) {
        int item = arr[0];
        arr[0] = arr[size - 1];
        heapifyDown(arr, size - 1);
        return item;
    }

    static void createHeap(int* arr, size_t size) {
        for(int i = 1; i <= size; i++) {
            int tempSize = i;
            heapifyUp(arr,tempSize);
        }
    }

    static void deleteHeap(int* arr, size_t size) {
        for( int i = size; i >= 1; i--) {
            int tempSize = i;
            int item = deleteItem(arr,tempSize);
            arr[tempSize - 1] = item;
        }
    }

    static void heapSort(int* arr, size_t size) {
        createHeap(arr,size);
        deleteHeap(arr,size);
    }
};

int main() {
    int arr[100] = {6,3,4,1,10};
    int size = 5;
    MaxHeap::heapSort(arr,size);
    for(int i = 0; i < size; i++) {
        cout<<arr[i]<<endl;
    }
}