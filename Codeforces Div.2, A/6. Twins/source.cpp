#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, sum = 0;
    vector<int> coins;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        sum += value;
        coins.push_back(value);
    }

    sort(coins.begin(), coins.end());

    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += coins[i];
        if (sum2 == sum / 2 && sum % 2 == 0) {
            cout << (n - i);
            return 0;
        }
        else if (sum2 > sum / 2) {
            cout << n - i;
            return 0;
        }
    }
}