#include <iostream>

using namespace std;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    if (n * m - 1 == t)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}