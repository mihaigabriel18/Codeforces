#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> tabla(n);
    for (int i = 0; i < n; i++)
        tabla[i].resize(m);
    
    for (int i = 0; i < n; i++)
        for (int j = 0 ; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.')
                tabla[i][j] = 1;
            else
                tabla[i][j] = 0;
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j < m; j++) {
            if (tabla[i][j] == 0)
                cout << "-";
            else {
                if ((i + j) % 2 == 0)
                    cout << "B";
                else
                    cout << "W";
            }
        }
        cout << endl;
    }
}