#include <iostream>

using namespace std;

int main() {
    int n, min_index, max_index, min = INT16_MAX, max = INT16_MIN;
    cin >> n;
    if (n == 1)
        return 0;

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        if (number <= min) {
            min = number;
            min_index = i;
        }
        if (number > max) {
            max = number;
            max_index = i;
        }
    }
    if (min_index > max_index)
        cout << max_index + (n - min_index) - 1;
    else
        cout <<  max_index + (n - min_index) - 2;
}