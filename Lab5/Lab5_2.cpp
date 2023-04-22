#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void gnomeSort(int *array, int size) {
    int pos = 0;
    while (pos < size) {
        if (pos == 0 || array[pos] <= array[pos - 1]) {
            pos++;
        } else {
            swap(array[pos], array[pos - 1]);
            pos--;
        }
    }
}

int main() {
    srand(time(NULL));
    const int rows = 10, columns = 10;
    int matrix[rows][columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            matrix[i][j] = rand() % 20 - 10; 
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int j = 0; j < columns; j++) {
        int *positives = new int[rows];
        int count = 0;
        for (int i = 0; i < rows; i++) {
            if (matrix[i][j] > 0) {
                positives[count++] = matrix[i][j];
            }
        }
        if (count > 1) {
            gnomeSort(positives, count);
            count = 0;
            for (int i = 0; i < rows; i++) {
                if (matrix[i][j] > 0) {
                    matrix[i][j] = positives[count++];
                }
            }
        }
        delete[] positives;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
