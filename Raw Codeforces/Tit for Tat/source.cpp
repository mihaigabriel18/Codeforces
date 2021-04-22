#include <iostream>

using namespace std;

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

void solve() {
    int n, k;
    int vec[101];

    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    
    int remaining;
    int nr_decrements = 0;
    int i;
    for (i = 0; i < n - 1; i++) {
        nr_decrements += vec[i];
        if (nr_decrements > k) {
            nr_decrements -= vec[i];
            remaining = k - nr_decrements;

            break;
        }
    }
    int nr_increment_last;
    if (i == (n - 1))
        nr_increment_last = nr_decrements;
    else
        nr_increment_last = nr_decrements + MIN(remaining, vec[i]);

    // print solution
    for (int j = 0; j < i; j++)
        cout << 0 << " ";
    
    // i
    if (i != n - 1) {
        cout << vec[i] - remaining << " ";

        for (int j = i + 1; j < n - 1; j++)
            cout << vec[j] << " ";
        
        cout << vec[n - 1] + nr_increment_last << endl;
    } else {
        cout << vec[n - 1] + nr_increment_last << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}