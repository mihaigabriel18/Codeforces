#include <iostream>
#include <string>

using namespace std;

void remove_vowels(string& s) {
    for (auto i = s.begin(); i != s.end(); )
        if (*i == 'a' || *i == 'A' || *i == 'o' || *i == 'O' ||
            *i == 'i' || *i == 'I' || *i == 'u' || *i == 'U' ||
            *i == 'e' || *i == 'E' || *i == 'y' || *i == 'Y')
            s.erase(i);
        else
            i++;
}

void to_lowercase(string& s) {
    for (int i = 0; i < s.size(); i++)
        if (s[i] <= 90)
            s[i] += 32;
}

void insert_dots(string& s) {
    for (int i = 0; i < s.size(); i+=2)
        s.insert(i, 1, '.');
}

int main() {
    string s;
    cin >> s;
    remove_vowels(s);
    to_lowercase(s);
    insert_dots(s);
    cout << s;
}