#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

void readArray(int arr[], int size) {
    cout << "Enter " << size << " integers:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

int findMinIndex(int arr[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

void swapWithNextMin(int arr[], int size) {
    int minIndex = findMinIndex(arr, size);
    if (minIndex < size - 1) {
        swap(arr[minIndex], arr[minIndex + 1]);
    }
}

void printArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int k;
    int arr[MAX_SIZE];

    cout << "Enter the size of the array (up to " << MAX_SIZE << "): ";
    cin >> k;

    readArray(arr, k);

    cout << "Original ";
    printArray(arr, k);

    swapWithNextMin(arr, k);

    cout << "Modified ";
    printArray(arr, k);

    return 0;
}
