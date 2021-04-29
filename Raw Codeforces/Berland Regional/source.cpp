#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define MAX_SIZE 200005

using namespace std;

unsigned long long ans[MAX_SIZE];
void solve() {
    unsigned long long n, univ[MAX_SIZE], knowledge[MAX_SIZE];
    vector<unsigned long long> ranks[MAX_SIZE];
    memset(ans, 0, MAX_SIZE * sizeof(unsigned long long));

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> univ[i];
    for (int i = 0; i < n; i++)
        cin >> knowledge[i];
    
    for (int i = 0; i < n; i++)
        ranks[univ[i]].push_back(knowledge[i]);

    for (int i = 1; i <= n; i++)
        if (ranks[i].size())
            sort(ranks[i].begin(), ranks[i].end(), std::greater<>());

    for (int i = 1; i <= n; i++)
        if (ranks[i].size())
            ranks[i].push_back(0);
    
    for (int i = 1; i <= n; i++)
        if (ranks[i].size())
            for (int j = ranks[i].size() - 2; j >= 0; j--)
                ranks[i][j] += ranks[i][j + 1];

    for (int i = 1; i <= n; i++)
        if (ranks[i].size())
            for (int j = 0; j < ranks[i].size() - 1; j++)
                ans[j] += ranks[i][0] - ranks[i][(ranks[i].size() - 1) - ((ranks[i].size() - 1) % (j + 1))];
    
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}