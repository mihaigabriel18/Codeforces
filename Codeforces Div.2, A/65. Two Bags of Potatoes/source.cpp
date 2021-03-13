#include <iostream>

using namespace std;

int main() {
    int y, k, n;
    cin >> y >> k >> n;

    int index = y / k + 1;
    if (index * k > n)
        cout << -1;
    else {
        for (int val = index * k; val <= n; val += k)
            cout << val - y << " ";
    }
}