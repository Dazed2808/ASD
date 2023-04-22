#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int m = (n + 1) / 2;
    for (int i = 0; i < m; i++) {
        arr[i] = arr[2 * i + 1];
    }

    for (int i = 1; i < m; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    cout << "Resulting array: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
