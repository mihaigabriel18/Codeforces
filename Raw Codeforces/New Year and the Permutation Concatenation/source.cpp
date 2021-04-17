#include <iostream>

using namespace std;

#define MAX_SIZE 1000001
#define MOD 998244353 

long long dp[MAX_SIZE];
long long factorial[MAX_SIZE];

int main() {
    dp[1] = 1;
    factorial[1] = 1;

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        factorial[i] = (i * factorial[i - 1]) % MOD;
        dp[i] = ((i * dp[i - 1]) % MOD + (i * (factorial[i - 1] - 1)) % MOD) % MOD;
    }

    cout << dp[n];
}