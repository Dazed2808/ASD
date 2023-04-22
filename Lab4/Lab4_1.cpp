#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printArray(double* arr, int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(double* arr, int size) {
    for (int i = 1; i < size; i++) {
        double key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;

    cout << "Enter the size of the array: ";
    cin >> n;

    double* arr = new double[n];

    srand(time(nullptr));
    for (int i = 0; i < n; i++) {
        arr[i] = static_cast<double>(rand()) / RAND_MAX;
    }

    cout << "Original ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted ";
    printArray(arr, n);

    delete[] arr;

    return 0;
}
