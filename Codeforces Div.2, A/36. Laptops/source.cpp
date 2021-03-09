#include <iostream>
// #include <pair>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbyfirst(const pair<int, int> &a,
                const pair<int, int> &b)
{
    return (a.first < b.first);
}

int main() {
    vector<pair<int, int>> laptops;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int value, key;
        cin >> value >> key;
        laptops.push_back(make_pair(value, key));
    }

    sort(laptops.begin(), laptops.end(), sortbyfirst);

    for (int i = 1; i < laptops.size(); i++) {
        if (laptops[i - 1].second > laptops[i].second) {
            cout << "Happy Alex";
            return 0;
        }
    }
    cout << "Poor Alex";
}