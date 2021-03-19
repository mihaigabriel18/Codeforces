#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    map<string, int> codes;

    codes["C"] = 1;
    codes["C#"] = 2;
    codes["D"] = 3;
    codes["D#"] = 4;
    codes["E"] = 5;
    codes["F"] = 6;
    codes["F#"] = 7;
    codes["G"] = 8;
    codes["G#"] = 9;
    codes["A"] = 10;
    codes["B"] = 11;
    codes["H"] = 12;

    vector<int> triade(3);
    vector<int> triade1(2);
    vector<int> triade2(2);
    vector<int> triade3(2);
    
    string code1, code2, code3;

    cin >> code1 >> code2 >> code3;

    triade[0] = codes[code1];
    triade[1] = codes[code2];
    triade[2] = codes[code3];

    sort(triade.begin(), triade.end());
    
    triade1[0] = triade[1] - triade[0];
    triade1[1] = triade[2] - triade[1];

    triade2[0] = triade[2] - triade[1];
    triade2[1] = 12 - triade[2] + triade[0];

    triade3[0] = 12 - triade[2] + triade[0];
    triade3[1] = triade[1] - triade[0];

    // sort(triade1.begin(), triade1.end());
    // sort(triade2.begin(), triade2.end());
    // sort(triade3.begin(), triade3.end());

    if (triade1[0] == 3 && triade1[1] == 4)
        cout << "minor";
    else if (triade1[0] == 4 && triade1[1] == 3)
        cout << "major";
    else if (triade2[0] == 3 && triade2[1] == 4)
        cout << "minor";
    else if (triade2[0] == 4 && triade2[1] == 3)
        cout << "major";
    else if (triade3[0] == 3 && triade3[1] == 4)
        cout << "minor";
    else if (triade3[0] == 4 && triade3[1] == 3)
        cout << "major";
    else
        cout << "strange";
}   