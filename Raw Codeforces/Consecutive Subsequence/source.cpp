#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_SIZE 200005
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

typedef struct entry {
    int max_length, max_element;
} entry;


int numbers[MAX_SIZE];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int, int> dp;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    int maximum = INT32_MIN;
    int maximum_number = -1;

    for (int i = 0; i < n; i++) {
        dp[numbers[i]] = 1 + dp[numbers[i] - 1];

        if (maximum < dp[numbers[i]]) {
            maximum = dp[numbers[i]];
            maximum_number = numbers[i];
        }
    }

    cout << maximum << endl;

    vector<int> sol;

    for (int i = n - 1; i >= 0 && maximum_number > 0; i--) {
        if (numbers[i] == maximum_number) {
            sol.push_back(i + 1);
            maximum_number--;
        }
    }

    for (int i = sol.size() - 1; i >= 0; i--)
        cout << sol[i] << " ";
}