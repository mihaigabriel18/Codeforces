#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> presents;
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        presents[val] = i;
    }

    for (auto entry : presents)
        cout << entry.second << " ";
}