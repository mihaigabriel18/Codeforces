#include <iostream>

#define MAX_SIZE 105

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

void solve() {
    int n, m;
    LL matrix[MAX_SIZE][MAX_SIZE];

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> matrix[i][j];
    
    LL sum = 0;
    for (int i = 1; i <= n / 2; i++)
        for (int j = 1; j <= m / 2; j++) {
            LL nr1, nr2, nr3, nr4;
            nr1 = matrix[i][j];
            nr2 = matrix[i][m - j + 1];
            nr3 = matrix[n - i + 1][j];
            nr4 = matrix[n - i + 1][m - j + 1];

            LL average = (nr1 + nr2 + nr3 + nr4) / 4;
            sum += abs(average - nr1) + abs(average - nr2) + abs(average - nr3)
                   + abs(average - nr4);
        }
    
    int mid_i = n / 2 + 1;
    int mid_j = m / 2 + 1;
    if (n % 2)
        for (int j = 1; j <= m / 2; j++) {
            LL nr1, nr2;
            nr1 = matrix[mid_i][j];
            nr2 = matrix[mid_i][m - j + 1];

            LL average = (nr1 + nr2) / 2;
            sum += abs(average - nr1) + abs(average - nr2);
        }

    if (m % 2)
        for (int i = 1; i <= n / 2; i++) {
            LL nr1, nr2;
            nr1 = matrix[i][mid_j];
            nr2 = matrix[n - i + 1][mid_j];

            LL average = (nr1 + nr2) / 2;
            sum += abs(average - nr1) + abs(average - nr2);
        }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}