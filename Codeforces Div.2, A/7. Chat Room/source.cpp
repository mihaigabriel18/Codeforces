#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    string mask = "hello";
    cin >> s;
    int index = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == mask[index]) {
            index++;
            if (index == mask.size()) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
}