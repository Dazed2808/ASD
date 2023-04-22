#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void shakerSort(int *array, int size) {
    int left = 0, right = size - 1, flag = true;
    while (left < right && flag) {
        flag = false;
        for (int i = left; i < right; i++) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
                flag = true;
            }
        }
        right--;
        for (int i = right; i > left; i--) {
            if (array[i - 1] > array[i]) {
                swap(array[i - 1], array[i]);
                flag = true;
            }
        }
        left++;
    }
}

int main() {
    srand(time(NULL));
    int rows, columns;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> columns;
    int *matrix = new int[rows * columns];
    int *sums = new int[columns];
    for (int j = 0; j < columns; j++) {
        sums[j] = 0;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i * columns + j] = rand() % 10;
            if (matrix[i * columns + j] % 3 != 0) {
                sums[j] += matrix[i * columns + j];
            }
            cout << matrix[i * columns + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    shakerSort(sums, columns);
    for (int j = 0; j < columns; j++) {
        cout << sums[j] << " ";
    }
    delete[] matrix;
    delete[] sums;
    return 0;
}
