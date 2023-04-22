#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    const int SIZE = 12;
    int A[SIZE];

    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % 21 - 10; 
    }

    cout << "Initial array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        if ((i + 1) % 3 == 0) { 
            int prev1 = A[i - 1];
            int prev2 = A[i - 2];

            if (prev1 != 0 && prev2 != 0) {
                A[i] = prev1 * prev2;
            }
            else { 
                A[i] = prev1 + prev2;
            }
        }
    }

    cout << "Modified array: ";
    for (int i = 0; i < SIZE; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
