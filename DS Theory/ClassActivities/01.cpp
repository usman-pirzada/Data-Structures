// searches_arrays.cpp
// Contains: linear_search_array, binary_search_iterative_array, interpolation_search_array
// Implementations use plain C-style arrays (int arr[], with length parameter).
#include <iostream>
using namespace std;

// Linear search: returns index of key or -1 if not found
int linear_search_array(const int arr[], int n, int key) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Iterative binary search (array must be sorted ascending)
int binary_search_iterative_array(const int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Iterative interpolation search (array sorted ascending, numeric values)
// Returns index of key or -1 if not found
int interpolation_search_array(const int arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        // Guard against division by zero if arr[low] == arr[high]
        if (arr[low] == arr[high]) {
            if (arr[low] == key) return low;
            else break;
        }

        long double fraction = (long double)(key - arr[low]) / (long double)(arr[high] - arr[low]);
        long double pos_ld = low + fraction * (high - low);
        int pos = static_cast<int>(pos_ld);

        // Ensure pos is within bounds
        if (pos < low) pos = low;
        if (pos > high) pos = high;

        if (arr[pos] == key) return pos;
        else if (arr[pos] < key) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Demo arrays (plain C-style arrays)
    int unsorted[] = { 23, 5, 87, 12, 43, 5, 99 };
    int n_unsorted = sizeof(unsorted) / sizeof(unsorted[0]);

    int sorted[] = { 3, 7, 12, 18, 24, 31, 42, 56, 77, 98 }; // ascending, numeric
    int n_sorted = sizeof(sorted) / sizeof(sorted[0]);

    int key;

    cout << "Demo - Linear Search on unsorted array\n";
    cout << "Array: ";
    for (int i = 0; i < n_unsorted; ++i) cout << unsorted[i] << " ";
    cout << "\nEnter key to linear-search: ";
    if (!(cin >> key)) return 0;
    int idx = linear_search_array(unsorted, n_unsorted, key);
    if (idx >= 0) cout << "Found at index " << idx << " (0-based)\n";
    else cout << "Not found\n";

    cout << "\nDemo - Binary Search on sorted array\n";
    cout << "Array: ";
    for (int i = 0; i < n_sorted; ++i) cout << sorted[i] << " ";
    cout << "\nEnter key to binary-search: ";
    if (!(cin >> key)) return 0;
    idx = binary_search_iterative_array(sorted, n_sorted, key);
    if (idx >= 0) cout << "Found at index " << idx << " (0-based)\n";
    else cout << "Not found\n";

    cout << "\nDemo - Interpolation Search on sorted (numeric) array\n";
    cout << "Array: ";
    for (int i = 0; i < n_sorted; ++i) cout << sorted[i] << " ";
    cout << "\nEnter key to interpolation-search: ";
    if (!(cin >> key)) return 0;
    idx = interpolation_search_array(sorted, n_sorted, key);
    if (idx >= 0) cout << "Found at index " << idx << " (0-based)\n";
    else cout << "Not found\n";

    return 0;
}
