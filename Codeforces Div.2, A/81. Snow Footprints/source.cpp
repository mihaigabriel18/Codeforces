#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;

    int i = 0;
    cin >> n >> s;
    while (s[i] == '.')
        i++;
    
    if (s[i] == 'L')
        cout << i + 1 << " " << i;
    else {
        while (s[i] == 'R')
            i++;
        cout << i << " " << i + 1;
    }
}