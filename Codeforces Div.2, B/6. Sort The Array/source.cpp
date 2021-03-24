#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, inflection1 = 0, inflection2 = 0;
    vector<int> elems;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int nr;
        cin >> nr;
        elems.push_back(nr);
    }

    for (int i = 0; i < n - 1; i++)
        if (elems[i] > elems[i+1]) {
            inflection1 = i;
            break;
        }

    for (int i = n - 1; i >= 0; i--)
        if (elems[i] < elems[i-1]) {
            inflection2 = i;
            break;
        }

    reverse(elems.begin() + inflection1, elems.begin() + inflection2 + 1);

    for (int i = 0; i < n - 1; i++)
        if (elems[i] > elems[i+1]) {
            cout << "no";
            return 0; 
        }
    
    cout << "yes" << endl << inflection1 + 1 << " " << inflection2 + 1;
}