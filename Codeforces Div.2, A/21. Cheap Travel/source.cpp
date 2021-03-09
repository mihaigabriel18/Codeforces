#include <iostream>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (a * m > b) {
        if ((n % m) * a > b)
            cout << (n / m + 1) * b;
        else 
            cout << (n / m) * b + (n % m) * a;
    }
    else
        cout << n * a;
}