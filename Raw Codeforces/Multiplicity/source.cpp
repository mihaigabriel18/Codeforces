#include <iostream>
#include <string.h>

using namespace std;

#define MAX_DIM 100001
#define MOD 1000000007

long long current[MAX_DIM], sum[MAX_DIM];
int numbers[MAX_DIM];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sum[0] = 1;

    for (int global_index = 1; global_index < n; global_index++) {
        current[0] = 1;
        for (int local_index = 1; local_index <= global_index; local_index++)
            current[local_index] = (numbers[global_index] % (local_index + 1) == 0) ? sum[local_index - 1] : 0;
        
        for (int i = 0; i <= global_index; i++)
            sum[i] += current[i];
    }

    long long sum_result = 0;
    for (int i = 0; i < n; i++)
        sum_result = (sum_result + sum[i]) % MOD;

    cout << sum_result;
}