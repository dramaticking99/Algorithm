#include <iostream>

class QuickSort {
private:
    int getPivot(int arr[], int low, int high) {
        int pivot = arr[low];
        int l = low + 1;
        int h = high;

        while (l <= h) {
            while (l <= h && arr[l] < pivot) {
                l++;
            }
            while (l <= h && arr[h] >= pivot) {
                h--; 
            }
            if (l < h) {
                std::swap(arr[l], arr[h]);
            }
        }

        std::swap(arr[low], arr[h]);
        return h;
    }

    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivotIndex = getPivot(arr, low, high);
            quickSort(arr, low, pivotIndex - 1);
            quickSort(arr, pivotIndex + 1, high);
        }
    }

public:
    void sort(int arr[], int size) {
        quickSort(arr, 0, size - 1);
    }
};

int main() {
    int arr[] = {3, 4, 2, 1, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    QuickSort sorter;
    sorter.sort(arr, size);

    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
