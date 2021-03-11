#include <iostream>

using namespace std;

int is_lucky(int n) {
    while(n) {
        if (n % 10 == 8)
            return 1;
        n = n / 10;
    }
    return 0;
}

int go_up(int a) {
    if (a % 10 < 8)
        return 8 - a % 10;
    
    int rest = a % 10;
    a = a / 10;
    while (a % 10 != 7) {
        if (a % 10 != 9)
            return (10 - rest) + 8;
        a = a / 10;
    }
    return 10 - rest;
}

int go_down(int a) {
    if (a <= 8)
        return 8 + a;

    if (a % 10 == 9)
        return 1;

    int rest = a % 10;
    a = a / 10;
    while (a % 10 != 9) {
        if (a % 10 != 0)
            return rest + 2;
        a = a / 10;
    }
    return rest + 1;
}

int main() {
    int a;
    cin >> a;

    if (is_lucky(abs(a + 1))) {
        cout << 1;
        return 0;
    }

    if (a > 0)
        cout << go_up(a);
    else
        cout << go_down(-a);
}