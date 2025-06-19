/**
 * Arrays are always passed by reference
 */

#include <iostream>
using namespace std;

int linearSearch(int[], int, int);
void reverseArray(int[], int);

int main() {
    
    // *** Finding smallest and largest in an array ***
    int array[] = {654, 64, 87, 645, 812, 311, 87, 344};

    int arr_size = sizeof(array) / sizeof(int);
    int smallest = INT_MAX;
    int largest = INT_MIN;
    int small_index;
    int large_index;

    for (int i = 0; i < arr_size; i++) {
        if(array[i] < smallest) {
            smallest = array[i];
            small_index = i;
        }

        if(array[i] > largest) {
            largest = array[i];
            large_index = i;
        }

        /**
         * Above if statements can be replaced by the below commented code
         */
        // smallest = min(array[i], smallest);
        // largest = max(array[i], largest);
    }

    cout << "The smallest number is \"" << smallest << "\" stored at index \"" << small_index << "\" of the array." << endl;
    cout << "The largest number is \"" << largest << "\" stored at index \"" << large_index << "\" of the array." << endl;
    // --------

    cout << "\n";
    
    // *** Find integer in array by linear searching ***
    int search_result1 = linearSearch(array, 87, arr_size);
    if(search_result1 != -1) {
        cout << "Target item(integer) found at index \"" << search_result1 << "\" of the array." << endl;
    } else {
        cout << "Target item(integer) not found in the array!!" << endl;
    }

    int search_result2 = linearSearch(array, 97, arr_size);
    if(search_result2 != -1) {
        cout << "Target item(integer) found at index \"" << search_result2 << "\" of the array." << endl;
    } else {
        cout << "Target item(integer) not found in the array!!" << endl;
    }
    // --------

    cout << "\n";

    // *** Reversing Array ***
    reverseArray(array, arr_size);
    cout << "Reversed Array:\n {";
    for(int i=0; i < arr_size; i++) {
        cout << array[i] << ", ";
    }
    cout << "\b\b}" << endl;
    // --------

    cout << endl;

    // *** Printing all the unique values of the given array ***
    int arr[] = {32, 45, 65, 74, 61, 45, 65, 32, 76};
    int arr_sz = sizeof(arr) / sizeof(int);

    cout << "\nUnique Values of the Array:\n {";
    for(int i=0; i<arr_sz; i++) {
        bool isUnique = true;

        for (int j=0; j<arr_sz; j++) {
            if(arr[i] == arr[j] && j!=i) {
                isUnique = false;
                break;
            }
        }

        if(isUnique) {
            cout << arr[i] << ", ";
        }
    }
    cout << "\b\b}" << endl;
    // --------

    cout << endl;

    // *** Print intersection of two arrays ***
    int arr1[] = {54, 32, 62, 41, 55, 86};
    int arr2[] = {46, 74, 41, 34, 54};
    int arr1_sz = sizeof(arr1) / sizeof(int);
    int arr2_sz = sizeof(arr2) / sizeof(int);

    cout << "Intersection values of the arrays:\n {";
    for (int i = 0; i < arr1_sz; i++) {
        for (int j = 0; j < arr2_sz; j++) {
            if(arr2[j] == arr1[i]) {
                cout << arr2[j] << ", ";
                break;
            }
        }
    }
    cout << "\b\b}" << endl;
    // --------

    cout << endl;

    // *** Swap min & max values of an array ***
    int min_value = INT_MAX;
    int max_value = INT_MIN;
    int index_for_min;
    int index_for_max;

    cout << "Array before swapping min & max values:\n {";
    for (int i = 0; i<arr_size; i++) {
        cout << array[i] << ", ";
    }
    cout << "\b\b}\n";

    for (int i = 0; i < arr_size; i++) {
        if (array[i] < min_value) {
            min_value = array[i];
            index_for_min = i;
        }

        if (array[i] > max_value) {
            max_value = array[i];
            index_for_max = i;
        }
    }
    swap(array[index_for_min], array[index_for_max]);

    cout << "Array after swapping min & max values:\n {";
    for (int i = 0; i<arr_size; i++) {
        cout << array[i] << ", ";
    }
    cout << "\b\b}\n";
    // --------
    
    return 0;
}

// => Linear Searching function
int linearSearch(int arr[], int target, int size) {
    for (int i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        }
    }

    return -1;
}

// => Reverse an Array (2 Pointer Approach)
void reverseArray(int arr[], int size) {
    int start = 0, end = size - 1;

    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
