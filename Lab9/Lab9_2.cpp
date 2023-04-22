#include <iostream>

int binarySearch(int arr[], int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid;  
        } else if (arr[mid] < target) {
            start = mid + 1;  
        } else {
            end = mid - 1;  
        }
    }
    return start;  
}

void insertElement(int arr[], int& size, int element) {
    int index = binarySearch(arr, 0, size - 1, element);
    for (int i = size - 1; i >= index; i--) {
        arr[i + 1] = arr[i]; 
    }
    arr[index] = element; 
    size++;
}

int main() {
    const int N1 = 10;
    int x[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int N = N1;
    std::cout << "Initial array: ";
    for (int i = 0; i < N; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
    int p;
    std::cout << "Enter a number to insert: ";
    std::cin >> p;
    insertElement(x, N, p);
    std::cout << "Updated array: ";
    for (int i = 0; i < N; i++) {
        std::cout << x[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
