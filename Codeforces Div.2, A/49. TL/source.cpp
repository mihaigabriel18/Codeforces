#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, c_min = INT16_MAX, c_max = INT16_MIN, i_min = INT16_MAX;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int nr;
        cin >> nr;
        if (nr > c_max)
            c_max = nr;
        if (nr < c_min)
            c_min = nr;
    }

    for (int i = 0; i < m; i++) {
        int nr;
        cin >> nr;
        if (nr < i_min)
            i_min = nr;
    }

    if (i_min <= c_max || i_min <= 2 * c_min) {
        cout << -1;
        return 0;
    }

    cout << max(c_max, 2 * c_min);
}