#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 105
#define MOD 1000000007
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

void solve() {
    int n, x;
    int arr[MAX_SIZE];
    int sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    
    if (sum == x)
        cout << "NO" << endl;
    else {
        sort(arr, arr + n, greater<int>());
        vector<int> sol;

        int sum_so_far = 0;
        for (int i = 0; i < n; i++) {
            if (sum_so_far + arr[i] == x) {
                // find the next smallest element if there is one
                int j = i;
                while (arr[j] == arr[i]) {
                    j++;
                    if (j == n)
                        break;
                }

                if (j != n) {
                    int aux = arr[j];
                    arr[j] = arr[i];
                    arr[i] = aux;
                } else {
                    sol.pop_back();
                    sol.pb(arr[i]);
                    arr[i+1] = arr[i-1];
                }
            }
            sol.pb(arr[i]);
            sum_so_far += arr[i];
        }

        cout << "YES" << endl;
        for (auto i : sol)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    IOS;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}   