#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbysec(const pair<string,int> &a, 
              const pair<string,int> &b) 
{ 
    return (a.second < b.second); 
} 

int main() {
    vector<pair<string, int>> choices;

    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        choices.push_back( make_pair(s, s.size() - 2));
    }

    sort(choices.begin(), choices.end(), sortbysec);

    int solution = 0;
    string sol;
    if (choices[0].second * 2 <= choices[1].second) {
        sol = choices[0].first[0]; 
        solution++;
    }

    if (choices[3].second / 2 >= choices[2].second) {
        sol = choices[3].first[0];
        solution++;
    }

    if (solution != 1)
        cout << "C";
    else
        cout << sol;
}