#include <iostream>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

using namespace std;

int main() {
    int ni, nj, oi, oj;
    cin >> ni >> nj >> oi >> oj;

    if (ni == oi || nj == oj)
        cout << 1 << " ";
    else
        cout << 2 << " ";
    
    if (abs(ni - oi) == abs(nj - oj))
        cout << 1 << " ";
    else if (abs(abs(ni - oi) - abs(nj - oj)) % 2 == 1)
        cout << 0 << " ";
    else
        cout << 2 << " ";

    cout << MAX(abs(ni-oi), abs(nj-oj));
}