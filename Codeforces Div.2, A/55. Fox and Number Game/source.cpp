#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> vec;

    cin >> n;
    for (int i = 0 ;i < n; i++) {
        int nr;
        cin >> nr;
        vec.push_back(nr);
    }

    sort(vec.begin(), vec.end());

    int poz = 0;
    while (true) {
        poz = 0;
        while (poz < vec.size() && vec[poz] == vec[0])
            poz++;
        if (poz == vec.size())
            break;
        vec[poz] = vec[poz] % vec[0];
        if (vec[poz] == 0)
            vec[poz] = vec[0];
        
        int swap = vec[poz];
        vec[poz] = vec[0];
        vec[0] = swap;
    }

    int sum = 0;
    for (int i: vec) {
        sum += i;
    }
    cout << sum;
}