#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        int sum_i = (arr[i] / 10) + (arr[i] % 10); 

        while (j >= 0 && ((arr[j] / 10) + (arr[j] % 10)) > sum_i) { 
            arr[j + 1] = arr[j]; 
            j--;
        }
        arr[j + 1] = key;
    }

   
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;

    return 0;
}
