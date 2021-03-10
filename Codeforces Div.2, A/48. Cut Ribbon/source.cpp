#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, c;
    int val[3];
    cin >> n >> a >> b >> c;

    val[0] = a;
    val[1] = b;
    val[2] = c;

    sort(val, val + 3);

    a = val[0];
    b = val[1];
    c = val[2];

    int nr = 0, nr_a, nr_b, nr_c;
    for (nr_c = 0; nr_c <= n / c; nr_c++) {
        for (nr_b = 0; nr_b <= n / b; nr_b++) {
            int nn = n - c * nr_c - b * nr_b;
            if (nn >= 0 && nn % a == 0) {
                nr_a = nn / a;
                int nr_aux = nr_a + nr_b + nr_c;
                if (nr_aux > nr)
                    nr = nr_aux;
            }
        }
    }
    cout << nr;
}