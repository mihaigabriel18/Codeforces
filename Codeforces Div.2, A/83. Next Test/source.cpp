#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> nr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        nr.push_back(number);
    }

    sort(nr.begin(), nr.end());

    int i = 0;
    while (nr[i] == i + 1)
        i++;

    cout << i + 1;
}