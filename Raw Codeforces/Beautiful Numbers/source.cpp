#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 1000005
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

ll fact[MAX_SIZE];

// cool exponentiation
ll power(ll x, int y, int p) {
    ll res = 1; // Initialize result
 
    x = x % p; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
     
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
ll modInverse(ll n, int p) {
    return power(n, p - 2, p);
}

// compute Comb n taken k modulo p
ll comb(int n, int k) {
    if (n < k)
        return 0;
    
    if (k == 0 || k == n)
        return 1;

    return ((fact[n] * modInverse(fact[n - k], MOD)) % MOD * modInverse(fact[k], MOD)) % MOD;
}

bool isMagicNumber(int a, int b, int number) {
    while (number) {
        if ((number % 10) != a && (number % 10) != b)
            return false;
        number = number / 10;
    }
    return true;
}

int main() {
    IOS;
    int a, b, n;
    ll ans = 0;
    
    cin >> a >> b >> n;
    int a_copy = a, b_copy = b;
    a = MIN(a, b);
    b = MAX(a, b);

    fact[0] = 1;
    fact[1] = 1;
    for (int i = 2; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    int diff = b - a;
    int minimal_sum = n * a;
    for (int i = 0; i <= n; i++) {
        if (isMagicNumber(a, b, minimal_sum + i * diff)) {
            ans = (ans + comb(n, i)) % MOD;
        }
    }
    
    cout << ans;
}