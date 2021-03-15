#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    vector<int> a;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int nr;
        cin >> nr;
        a.push_back(nr);
    }
    
    sort(a.begin(), a.end());

    int covered = k;
    int nr_popped = 0;
    while (covered < m) {
        if (a.empty()) {
            cout << -1;
            return 0;
        }
        int popped = a.back();
        nr_popped++;

        a.pop_back();

        covered += popped - 1;
    }

    cout << nr_popped;
}