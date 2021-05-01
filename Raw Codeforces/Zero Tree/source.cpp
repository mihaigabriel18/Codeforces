#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 100005
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

unordered_map<int, vector<int>> tree;
vector<int> values;
vector<bool> visited;
ll ans = 0;

pair<ll, ll> dfs(int start) {
    visited[start] = true;
    
    ll max_poz = 0, max_neg = 0;
    bool is_leaf = true;
    for (auto child : tree[start]) {
        if (visited[child] == false) {
            pair<ll, ll> res = dfs(child);
            if (res.ff > max_neg)
                max_neg = res.ff;
            if (res.ss > max_poz)
                max_poz = res.ss;
            is_leaf = false;
        }
    }

    if (is_leaf) {
        // ans += abs(values[start]);
        if (values[start] >= 0)
            return mp(0, values[start]);
        else
            return mp(abs(values[start]), 0);
    }

        ll diff = -max_poz + max_neg + values[start];
    if (diff >= 0)
        max_poz += diff;
    else
        max_neg += abs(diff);

    return mp(max_neg, max_poz);
}

int main() {
    IOS;
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int source, dest;
        cin >> source >> dest;
        tree[source].pb(dest);
        tree[dest].pb(source);
    }

    values.pb(0);
    visited.pb(false);  
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        values.pb(number);
        visited.pb(false); 
    }

    pair<ll, ll> res = dfs(1);

    cout << res.ff + res.ss;

}