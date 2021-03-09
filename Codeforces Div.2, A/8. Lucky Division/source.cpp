#include <iostream>

using namespace std;

bool is_lucky(int nr) {
    while (nr) {
        if (nr % 10 != 4 && nr % 10 != 7)
            return false;
        nr /= 10;
    }
    return true;
}

int main() {
    int nr;
    cin >> nr;
    if (is_lucky(nr)) {
        cout << "YES";
        return 0;
    }
    for (int i = 1; i <= nr/2; i++) {
        if (nr % i == 0 && is_lucky(i)) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}