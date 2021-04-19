#include <iostream>

using namespace std;

#define MAX_SIZE 100005
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int numbers[MAX_SIZE];

int gcd(int a,int b){
	int t;
	while(b){
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        int nr;
        cin >> nr;
        numbers[i] = nr;
    }

    int overall_gcd = numbers[0];
    for (int i = 1; i < n; i++)
        overall_gcd = gcd(overall_gcd, numbers[i]);
    
    if (overall_gcd > 1) {  // there are divisors greater than 2
        cout << "Yes" << endl << 0 << endl;
        return 0;
    }

    // try to make the gcd 2
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        if (numbers[i] % 2 == 1)  // odd
            if (numbers[i + 1] % 2 == 1) {  // next odd
                count++;
                numbers[i + 1] = 0; // make the number even
            } else {
                count += 2;
            }
    }

    if (numbers[n - 1] % 2 == 1)
        count += 2; // previous is guranteed even

    cout << "YES" << endl << count << endl;
}