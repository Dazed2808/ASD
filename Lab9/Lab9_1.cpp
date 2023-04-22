#include <iostream>
#include <cstdlib>
#include <ctime>

int generateRandomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  
}

int findMaxIndex(int arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void insertAfterMax(int arr[], int size, int element) {
    int maxIndex = findMaxIndex(arr, size);
    arr[size] = element;
    size++;
    for (int i = size - 1; i > maxIndex + 1; i--) {
        std::swap(arr[i], arr[i - 1]);
    }
}

int main() {
    const int SIZE = 14;
    int a[SIZE];
    srand(time(0));  
    for (int i = 0; i < SIZE; i++) {
        a[i] = generateRandomInt(30, 150);
    }
    std::cout << "Initial array: ";
    printArray(a, SIZE);
    int target;
    std::cout << "Enter a number to search for: ";
    std::cin >> target;
    int index = linearSearch(a, SIZE, target);
    if (index == -1) {
        std::cout << target << " not found, inserting after maximum element." << std::endl;
        insertAfterMax(a, SIZE, target);
        std::cout << "Updated array: ";
        printArray(a, SIZE);
    } else {
        std::cout << target << " found at index " << index << "." << std::endl;
    }
    return 0;
}
