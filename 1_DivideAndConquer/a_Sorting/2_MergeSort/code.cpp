#include<iostream>
#include<array>
using namespace std;

class MergeSort {
    
    private:

        static void merge(int arr[], int l, int h) {
            int mid = (l + h)/2;
            int size = h - l + 1;
            
            int tempArr[size];

            int i = l;
            int j = mid + 1;
            int k = 0;

            while(i < mid + 1 && j < h + 1) {
                if(arr[i] > arr[j]){
                    tempArr[k++] = arr[j++];
                } else {
                    tempArr[k++] = arr[i++];
                }
            }

            if(i < mid + 1) {
                while(i < mid + 1) {
                    tempArr[k++] = arr[i++];
                }
            }

            if(j < h + 1) {
                while(j < h + 1) {
                    tempArr[k++] = arr[j++];
                }
            }

            for(int i = 0; i < size; i++) {
                arr[l++] = tempArr[i];
            }


        }

    public: 

        static void mergeSort(int arr[], int l, int h) {
            
            if(l == h) {
                return;
            }

            int mid = (l + h)/2;

            mergeSort(arr, l , mid);
            mergeSort(arr, mid+1, h);
            merge(arr, l , h);

        }    
        
};

int main() {
    int arr[5] = {3,4,2,1,8};
    MergeSort::mergeSort(arr,0,4);

    for(int i = 0; i < 5; i++) {
        cout<<arr[i]<<endl;
    }
}