#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    string s;
    map<int, int> m;

    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] != '+')
            m[s[i]]++;
    
    string final;
    for (auto i : m) {
        int key = i.first;
        int value = i.second;

        for (int j = 0; j < value; j++) {
            final.push_back(key);
            final.push_back('+');
        }
    }
    final.pop_back();

    cout << final;
}