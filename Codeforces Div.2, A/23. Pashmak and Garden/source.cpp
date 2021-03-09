#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int x1, x2, y1, y2;
    int x3, x4, y3, y4;
    int l;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 != x2 && y1 != y2 && (abs(x2-x1) != abs(y2-y1))) {
        cout << -1;
        return 0;
    }
    
    if (x1 == x2) {
        l = abs(y1-y2);
        x3 = x1 + l;
        x4 = x1 + l;
        y3 = y2;
        y4 = y1;
    }
    else if (y1 == y2) {
        l = abs(x1-x2);
        y3 = y1 + l;
        y4 = y1 + l;
        x3 = x2;
        x4 = x1;
    }
    else {
        if ((x2 > x1 && y2 > y1) || (x2 < x1 && y2 < y1)) {
            l = abs(x2-x1);
            y3 = min(y1, y2);
            x3 = min(x1, x2) + l;
            y4 = min(y1, y2) + l;
            x4 = min(x1, x2);
        }
        else {
            l = abs(x2-x1);
            y3 = min(y1, y2);
            x3 = min(x1, x2);
            y4 = min(y1, y2) + l;
            x4 = min(x1, x2) + l;
        }
    }
    cout << x3 << " " << y3 << " " << x4 << " " << y4;
}