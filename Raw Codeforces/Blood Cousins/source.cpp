#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define MAX_SIZE 100005

using namespace std;

// log2(100005) < 20
int num[MAX_SIZE], dp[MAX_SIZE][20], dis[MAX_SIZE], d[MAX_SIZE], f[MAX_SIZE];
                                                    // discovery  //finnish
map<int, vector<int>> children;

int t = 0;
void dfs(int a,int p){
    t++;
    d[a] = t;
    for(auto i:children[a]){
        if(i != p){
            dis[i] = dis[a]+1;
            dfs(i,a);
        }
    }
    f[a] = t;
}

int main() {
    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    for (int i = 1; i <= n; i++) {
        children[num[i]].push_back(i);
    }
    dfs(0, 0);
    
    vector<pair<int, int>> v[MAX_SIZE];
    for (int i = 1; i <= n; i++)
        v[dis[i]].push_back({d[i], f[i]});
    for (int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end());

    for (int i = 1; i <= n; i++)
        dp[i][0] = num[i]; // going 2^0 levels upwards
    
    for (int i = 1; i <= n; i++)
        for (int k = 1; k < 20; k++)
            dp[i][k] = dp[dp[i][k - 1]][k - 1];
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int member, cousin_grade;
        cin >> member >> cousin_grade;
        int cousin_grade_copy = cousin_grade;
        // get the ancestor
        int ancestor = member, index_pow_2 = 0;
        while (cousin_grade != 0) {
            if (cousin_grade % 2 == 1) {
                ancestor = dp[ancestor][index_pow_2];
            }
            index_pow_2++;
            cousin_grade = cousin_grade / 2;
        }

        if (ancestor == 0) {
            cout << 0 << " ";
        } else {
            int lo = -1, hi = v[dis[member]].size();
            while (hi - lo > 1) {
                int mid = (lo+hi)/2;
                if (v[dis[member]][mid].first < d[ancestor])
                    lo = mid;
                else
                    hi = mid;
            }
            int keep_index = hi;
            lo = -1, hi = v[dis[member]].size();
            while(hi - lo > 1) {
                int mid = (lo+hi)/2;
                if (v[dis[member]][mid].second <= f[ancestor])
                    lo = mid;
                else
                    hi = mid;
            }
            cout << lo - keep_index << " ";
        }
    }
}