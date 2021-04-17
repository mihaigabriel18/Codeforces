#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_DIM 1000001
#define MOD 1000000007

long long dp[MAX_DIM];
int numbers[MAX_DIM];

bool descending(int i, int j) { return i > j; }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int nr = numbers[i];
        // get al divisors of the number
        vector<int> divisors;
        
        for (int j = 1; j * j <= nr; j++) {
            if (nr % j == 0) {
                if (j * j == nr) {
                    divisors.push_back(j); // push it only 1 time
                } else {
                    divisors.push_back(j);  // push it 2 times
                    divisors.push_back(nr / j);
                }
            }
        }
        sort(divisors.begin(), divisors.end(), descending);
        for (int j = 0; j < divisors.size(); j++) {
            dp[divisors[j]] = (dp[divisors[j]] + dp[divisors[j] - 1]) % MOD;
        }
    }

    long long sum_result = 0;
    for (int i = 1; i <= n; i++)
        sum_result = (sum_result + dp[i]) % MOD;

    cout << sum_result;
}