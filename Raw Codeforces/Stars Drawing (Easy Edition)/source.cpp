#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MAX_SIZE 1005

typedef struct entry {
    int left, up, right, down;
} entry;

entry dp[MAX_SIZE][MAX_SIZE];
char stars[MAX_SIZE][MAX_SIZE];
int regenerated[MAX_SIZE][MAX_SIZE];
int r[MAX_SIZE][MAX_SIZE], l[MAX_SIZE][MAX_SIZE], d[MAX_SIZE][MAX_SIZE], u[MAX_SIZE][MAX_SIZE];
int result[MAX_SIZE][MAX_SIZE];

int min4(int a1, int a2, int a3, int a4) {
    return MIN(MIN(MIN(a1, a2), a3), a4);
}

int max4(int a1, int a2, int a3, int a4) {
    return MAX(MAX(MAX(a1, a2), a3), a4);
}

typedef struct res_entry {
    int r, c, v;
} res_entry;

vector<res_entry> res;

int main() {
    int m, n;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> stars[i][j];
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (stars[i][j] == '*') {
                dp[i][j].left = 1 + dp[i][j - 1].left;
                dp[i][j].up = 1 + dp[i - 1][j].up;
            }

    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--)
            if (stars[i][j] == '*') {
                dp[i][j].right = 1 + dp[i][j + 1].right;
                dp[i][j].down = 1 + dp[i + 1][j].down;
            }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            result[i][j] = min4(dp[i][j].down, dp[i][j].left, dp[i][j].right, dp[i][j].up);
            if (result[i][j] > 1) {
                res_entry aux;
                aux.r = i;
                aux.c = j;
                aux.v = result[i][j];
                res.push_back(aux);
            }
        }

    // build solution
    for (auto entr : res) {
        l[entr.r][entr.c] = entr.v;
        r[entr.r][entr.c] = entr.v;
        u[entr.r][entr.c] = entr.v;
        d[entr.r][entr.c] = entr.v;
    }

    // regenerate solution
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (r[i][j] != 0 && r[i][j + 1] < r[i][j])
                r[i][j + 1] = r[i][j] - 1;
        }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (d[i][j] != 0 && d[i + 1][j] < d[i][j])
                d[i + 1][j] = d[i][j] - 1;
        }
        
    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--) {
            if (l[i][j] != 0 && l[i][j - 1] < l[i][j])
                l[i][j - 1] = l[i][j] - 1;
        }

    for (int i = n; i >= 1; i--)
        for (int j = m; j >= 1; j--) {
            if (u[i][j] != 0 && u[i - 1][j] < u[i][j])
                u[i - 1][j] = u[i][j] - 1;
        }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            regenerated[i][j] = max4(l[i][j], r[i][j], u[i][j], d[i][j]);
        }

    // check with original mask 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (stars[i][j] == '*' && regenerated[i][j] == 0) {
                cout << -1;
                return 0;
            }
        }

    // print solution
    cout << res.size() << endl;
    for (auto local_res : res) {
        cout << local_res.r << " " << local_res.c << " " << local_res.v - 1 << endl;
    }
}