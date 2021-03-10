#include <iostream>

using namespace std;

int main() {
    long long n, l, mul = 1;
    cin >> n >> l;
    for (int i = 0; ; i++) {
        mul = mul * n;
        if (mul == l) {
            cout << "YES" << endl << i;
            break;
        }
        else if (mul > l) {
            cout << "NO";
            break;
        }
    }
}