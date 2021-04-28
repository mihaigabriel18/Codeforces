#include <iostream>
#include <cmath>

using namespace std;

void solve() {
    unsigned long long number;
    unsigned long long n2050 = 2050;
    cin >> number;

    int nr_digits = log10(number) + 1;
    int nr_zeros = nr_digits - 4;
    unsigned long long aux2050 = 2050 * pow(10, nr_zeros);
    int solution = 0;
    while (number >= 2050) {
        solution += number / aux2050;
        number = number % aux2050;
        aux2050 = aux2050 / 10;
    }

    if (number == 0)
        cout << solution << endl;
    else
        cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}