#include <iostream>
#include<string>
using namespace std;
int main() {
    int* arr;
    int n;
    // Asking the user for the number of elements
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Dynamically allocating memory for an array of integers
    arr = new int[n];

    // Taking input for each element of the array
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }
    // Displaying the elements of the array
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";;
    }
    cout << endl;
    // Freeing the dynamically allocated memory
    delete[] arr;
    return 0;
}