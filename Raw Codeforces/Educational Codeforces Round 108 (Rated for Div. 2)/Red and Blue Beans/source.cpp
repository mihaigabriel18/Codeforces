#include <iostream> 

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;

void solve() {
    int r, b, d;
    cin >> r >> b >> d;

    if (d == 0) {
        if (r == b)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }

    int max_containers = MIN(r, b);
    int diff = abs(r - b);
    int ceiling = (diff % d == 0) ? diff / d : ((diff / d) + 1);
    if (max_containers < ceiling) // max cotainers smaller than the
                                           // ceilein of the division
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}