#include<iostream>
#include<cstddef>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//Solve The bug during heapSort 
//the bug is because the heapSort won't work with the heap vector using the vector.size() function.
// Also create a class that implements the heap with recurrsion

class MaxHeap {

private:

    vector<int>heap;

        void heapifyUp () {
        int index = heap.size();
        int parentIndex = index/2;

        while(parentIndex >= 1 && heap[parentIndex - 1] < heap[index - 1]) {
            swap(heap[parentIndex - 1], heap[index - 1]);
            index = parentIndex;
            parentIndex = index/2;
        }
    }

        void heapifyDown () {
        int index = 1;
        int size = heap.size();
        int leftChild = index*2 > size ? -1 : index*2;
        int rightChild = index*2 + 1 > size ? -1 : index*2 + 1;
        int greaterChild = -1;

        if (leftChild != -1 && rightChild != -1) {
            if (heap[leftChild - 1] > heap[rightChild - 1]) {
               greaterChild = leftChild;
            } else {
               greaterChild = rightChild;
            }
        } else if( leftChild != -1) {
            greaterChild = leftChild;
        }

        while (greaterChild != -1 && heap[index - 1] < heap[greaterChild - 1]){
            swap(heap[index - 1], heap[greaterChild - 1]);
            index = greaterChild;
            greaterChild = -1;
            int leftChild = index*2 > size ? -1 : index*2;
            int rightChild = index*2 + 1 > size ? -1 : index*2 + 1;

            if (leftChild != -1 && rightChild != -1) {
              if (heap[leftChild - 1] > heap[rightChild - 1]) {
                 greaterChild = leftChild;
              } else {
                 greaterChild = rightChild;
              }
            } else if( leftChild != -1) {
                   greaterChild = leftChild;
                }
        }
        heap.pop_back();
    }
    
public:    
    
    MaxHeap(vector<int>heapVector) {
        this->heap = heapVector;
    }
    
    void insertItem (int item) {
        heap.push_back(item);
        heapifyUp();        
    }

    int deleteItem () {
        int item = heap[0];
        heap[0] = heap[heap.size() - 1];
        heapifyDown();
        return item;
    }

    void createHeap() {
        for(int i = 1; i <= heap.size(); i++) {
            heapifyUp();
        }
    }

    void deleteHeap() {
        for( int i = heap.size(); i >= 1; i--) {
            int tempSize = i;
            int item = deleteItem();
            heap[tempSize - 1] = item;
        }
    }

    static void heapSort(vector<int>& arr) {
        MaxHeap* heap = new MaxHeap(arr);
        heap->createHeap();
        heap->deleteHeap();
        arr = heap->getHeap();
        delete heap;
    }

    int getSize() {
        return heap.size();
    }

    vector<int> getHeap() {
        return heap;
    }

    void printHeap() {
        cout<<"the elements in the heap are as follows : ";
        for(int i = 0; i < heap.size() ; i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {

    vector<int>arr = {15,10,6,3,4,1};

    MaxHeap* heapToTest =new  MaxHeap(arr);

    int deletedItem = heapToTest->deleteItem();

    heapToTest->printHeap();

    
    
    
}


