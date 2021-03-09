#include <iostream>
#include <string>

using namespace std;

void to_lowercase(string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] <= 90)
            s[i] += 32;
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    to_lowercase(s1);
    to_lowercase(s2);
    int result = s1.compare(s2);
    if (result < 0)
        cout << -1;
    else if (result == 0)
        cout << 0;
    else
        cout << 1;
}