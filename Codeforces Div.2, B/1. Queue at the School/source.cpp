#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, t;
    string s;

    cin >> n >> t >> s;
    for (int j = 0; j < t; j++) {
        for (int i = 0; i < n; i++)
            if (s[i] == 'B' && s[i+1] == 'G') {
                s[i] = 'G';
                s[i+1] = 'B';
                i++;
            }
    }
    
    cout << s;
}