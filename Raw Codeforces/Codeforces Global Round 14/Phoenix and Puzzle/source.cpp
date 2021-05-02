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

bool isSquare(int x) {
    int square = sqrt(x);
    if (square * square == x)
        return true;
    else    
        return false;
}

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "NO" << endl;
        return;
    }

    if ((n % 4 == 0 && isSquare(n / 4)) ||
        (n % 2 == 0 && isSquare(n / 2)))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    IOS;
    int t;
    cin >> t;

    while(t--)
        solve();
}