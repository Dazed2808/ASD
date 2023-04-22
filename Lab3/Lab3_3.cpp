#include <iostream>

using namespace std;

const int N = 6;

int main()
{
    float A[N][N];
    float sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 100 / 10.0;
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N - i - 1; j++) {
            sum += A[i][j];
        }
    }

    cout << sum << endl;

    return 0;
}
