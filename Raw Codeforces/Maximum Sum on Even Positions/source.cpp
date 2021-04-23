#include <iostream>
#include <vector>

#define MAX_SIZE 200005
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

using namespace std;

typedef long long LL;

LL kadane(vector<LL> arr) {
    LL max_so_far = INT64_MIN, max_ending_here = 0;

    for (int i = 0; i < arr.size(); i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        
        if (max_ending_here < 0)
            max_ending_here = 0;
    }

    return max_so_far;
}

void solve() {
    vector<LL> diff1, diff2;
    LL n, original_sum = 0;
    LL nums[MAX_SIZE];

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (i % 2 == 0)
            original_sum += nums[i];
    }
    
    for (int i = 0; i + 1 < n; i += 2)
        diff1.push_back(nums[i + 1] - nums[i]);
    
    for (int i = 1; i + 1 < n; i += 2)
        diff2.push_back(nums[i] - nums[i + 1]);

    LL kadane_res1 = kadane(diff1);
    LL kadane_res2 = kadane(diff2);

    cout << original_sum + MAX(0, MAX(kadane_res1, kadane_res2)) << endl;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}