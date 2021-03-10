#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, sum_1 = 0, sum_2 = 0;
    vector<pair<int, int>> domino;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        sum_1 += n1;
        sum_2 += n2;
        domino.push_back(make_pair(n1, n2));
    }

    if (sum_1 % 2 == 0 && sum_2 % 2 == 0)
        cout << 0;
    else if ((sum_1 % 2 == 1 && sum_2 % 2 == 0) ||
             (sum_1 % 2 == 0 && sum_2 % 2 == 1))
        cout << -1;
    else {
        for (int i = 0; i < n; i++)
            if ((domino[i].first % 2 == 1 && domino[i].second % 2 == 0) ||
                (domino[i].first % 2 == 0 && domino[i].second % 2 == 1)) {
                    cout << 1;
                    return 0;
                }
        cout << -1;
    }
}