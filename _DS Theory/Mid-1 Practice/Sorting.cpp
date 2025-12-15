#include <iostream>
using namespace std;

void bubbleSort(int arr[], int size) {  // Stable & In-place [Non-Adaptive] - O(n²)
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void modifiedBubbleSort(int arr[], int size) {  // Stable, Adaptive & In-place - O(n²)
    for (int i = 0; i < size - 1; i++) {
        bool isSwap = false;

        for (int j = 0; j < size - 1 - i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }

        if(isSwap == false) {
            return;
        }
    }
}

void combSort(int arr[], int size) {    // Adaptive & In-place [Non-Stable] - O(n²)
    int gap = size;
    bool isSwap = true;

    while (gap > 0 || isSwap) {
        gap = gap/1.3;
        if(gap < 1) gap = 1;
        isSwap = false;

        for (int i = 0; i < size - gap; i++) {
            if(arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                isSwap = true;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i; // starting of unsorted part

        for (int j = i + 1; j < size; j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if(minIdx != i) {
            swap(arr[i], arr[minIdx]);
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int currVal = arr[i];
        int prevIdx = i - 1;

        while(prevIdx >= 0 && arr[prevIdx] > currVal) {
            arr[prevIdx + 1] = arr[prevIdx];
            prevIdx--;
        }
        
        arr[prevIdx + 1] = currVal;
    }
}

int main() {
    

    
    return 0;
}
