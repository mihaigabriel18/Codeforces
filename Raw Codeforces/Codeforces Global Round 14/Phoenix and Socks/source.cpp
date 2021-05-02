#include <bits/stdc++.h>

using namespace std;

#define MAX_SIZE 200005
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

int binarySearch(int* arr, int x, int dim) {
    int l = 0, r = dim - 1;
    while (l <= r) {
        int m = (l+r)/2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            r = m  - 1;
        else
            l = m + 1;
    }
    
    return -1;
}

void solve() {
    int n, l, r;
    int left[MAX_SIZE], right[MAX_SIZE];
    memset(left, 0, sizeof(left));
    memset(right, 0, sizeof(right));
    cin >> n >> l >> r;

    for (int i = 0; i < l; i++)
        cin >> left[i];
    
    for (int i = 0; i < r; i++)
        cin >> right[i];

    sort(left, left + l, greater<>());
    sort(right, right + r, greater<>());

    int ans = 0;
    if (l > r) {
        int aux = l;
        l = r;
        r = aux;

        int left_copy[MAX_SIZE], right_copy[MAX_SIZE];
        memcpy(left_copy, left, sizeof(left));
        memcpy(right_copy, right, sizeof(right));
        
        memcpy(left, right_copy, sizeof(right_copy));
        memcpy(right, left_copy, sizeof(left_copy));
    }

    for (int i = 0, j = 0; i < l && j < r; ) {
        if (right[j] < left[i]) {
            i++;
            continue;
        }
        if (left[i] < right[j]) {
            j++;
            continue;
        }
        if (left[i] == right[j]) {
            right[j] = MAX_SIZE;
            left[i] = MAX_SIZE;
            j++;
            i++;
            continue;
        }
    }


    // for (int i = 0; i < l; i++) {
    //     int poz = binarySearch(right, left[i], r);
    //     if (poz != -1) {
    //         cout << "poz: " << poz << " i: " << i << endl;
    //         right[poz] = MAX_SIZE;
    //         left[i] = MAX_SIZE;
    //     }
    // }
    
    for (int i = 0; i < r; ) {
        if (right[i++] != MAX_SIZE) {
            int keep = i - 1;
            while (right[i] == MAX_SIZE) {
                i++;
                if (i >= r)
                    break;
            }
            if (i >= r)
                break;
            if (right[i] == right[keep]) {
                right[keep] = -1;
                right[i] = -1;
            }
        }
    }

    int unmatch_l = 0, unmatch_r = 0;
    for (int i = 0; i < l; i++)
        if (left[i] != MAX_SIZE)
            unmatch_l++;

    for (int i = 0; i < r; i++)
        if (right[i] != MAX_SIZE)
            unmatch_r++;
        
    int match_longer = 0;
    for (int i = 0; i < r; i++)
        if (right[i] == -1)
            match_longer++;

    int going_to_be_moved = MIN(r - l, match_longer);
    
    int remaining_diff = (r - l) - going_to_be_moved;
    ans += MIN(unmatch_l, unmatch_r) + remaining_diff + going_to_be_moved / 2;

    cout << ans << endl;
}

int main() {
    IOS;
    int t;
    cin >> t;
    while(t--)
        solve();
}