#include <iostream>
#include <math.h>
#include <map>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    int n;
    long long product = 1;

    cin >> n;


    vector<int> result;
    for (int i = 1; i < n; i++) {
        if (gcd(i, n) == 1) {
            result.push_back(i);
            product = (i * product) % n;
        }
    }

    if (product == 1) {
        product = -1;
        cout << result.size() << endl;
    } else {
        cout << result.size() - 1 << endl;
    }



    for (int i = 0; i < result.size(); i++)
        if (result[i] != product)
            cout << result[i] << " ";

}