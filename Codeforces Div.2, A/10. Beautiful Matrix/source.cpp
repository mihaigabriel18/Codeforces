#include <iostream>

using namespace std;

int main() {
    int matrix[5][5];
    int one_i, one_j;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                one_i = i;
                one_j = j;
            }
        }
    cout << abs(one_i - 2) + abs(one_j - 2);
}