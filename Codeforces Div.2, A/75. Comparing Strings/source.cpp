#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.size() != s2.size()) {
        cout << "NO";
        return 0;
    }

    int invertions = 0;
    int index1 = -1, index2 = -1;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            invertions++;
            if (index1 == -1)
                index1 = i;
            else if (index2 == -1)
                index2 = i;
        }
    }

    if (invertions != 2)
        cout << "NO";
    else {
        if (s1[index1] == s2[index2] && s1[index2] == s2[index1])
            cout << "YES";
        else
            cout << "NO";
    }
}