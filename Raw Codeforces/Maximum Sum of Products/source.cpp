#include <iostream>

#define MAX_SIZE 5005

using namespace std;

uint64_t partial_sum[MAX_SIZE];
uint64_t dp[2][MAX_SIZE];

int main() {
    uint64_t n, a[MAX_SIZE], b[MAX_SIZE];
    uint64_t raw_result = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = n; i >= 1; i--) {
        raw_result += a[i] * b[i];
        partial_sum[i] = raw_result;
    }
 
    int64_t max = 0;
    for (int i = 1; i <= n; i++) {
        dp[0][i] = raw_result;
        if (dp[0][i] > max)
            max = dp[0][i];
    }

    for (int i = 1; i <= n - 1; i++) {
        dp[1][i] = (raw_result - partial_sum[i]) + (partial_sum[i + 2]) +
                       a[i + 1] * b[i] + a[i] * b[i + 1];
        if (dp[1][i] > max)
            max = dp[1][i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            int local_i, local_j;
            local_i = j;
            local_j = j + i;
            dp[i % 2][j] = dp[i % 2][j + 1] - a[local_i] * b[local_i] -
                                   a[local_j] * b[local_j] + a[local_i] * b[local_j] +
                                   a[local_j] * b[local_i];
            if (dp[i % 2][j] > max)
                max = dp[i % 2][j];
        }
    } 
    cout << max;
}