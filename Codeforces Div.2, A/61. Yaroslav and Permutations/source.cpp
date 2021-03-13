#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    map<int, int> nr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        nr[num]++;
    }

    int max = INT16_MIN;
    int sum = 0;
    for (auto i : nr) {
        sum += i.second;
        if (i.second > max)
            max = i.second;
    }
    sum -= max;

    if (sum >= max - 1) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}