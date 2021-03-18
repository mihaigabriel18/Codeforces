#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int n;
    map<string, int> alcohol;

    alcohol["ABSINTH"] = 1;
    alcohol["BEER"] = 1;
    alcohol["BRANDY"] = 1;
    alcohol["CHAMPAGNE"] = 1;
    alcohol["GIN"] = 1;
    alcohol["RUM"] = 1;
    alcohol["SAKE"] = 1;
    alcohol["TEQUILA"] = 1;
    alcohol["VODKA"] = 1;
    alcohol["WHISKEY"] = 1;
    alcohol["WINE"] = 1;

    int number = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string reg;
        cin >> reg;
        if (alcohol[reg] == 1)
            number++;
        else {
            try {
                if (stoi(reg) < 18)
                    number++;
            } catch ( const invalid_argument& e) {

            }
        }
    }
    cout << number;
}