#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<int> nr;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;
        nr.push_back(number);
    }

    vector<pair<int, int>> pairs;

    for (int i = 0; i < n - 1; i++)
        if (nr[i] < nr[i+1])
            pairs.push_back(make_pair(nr[i], nr[i+1]));
        else
            pairs.push_back(make_pair(nr[i+1], nr[i]));
    
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1; j++) 
            if (i != j) {
                if (pairs[i].first < pairs[j].first &&
                    pairs[i].second > pairs[j].first) {
                    cout << pairs[i].first << " " << pairs[i].second << " " << pairs[j].first << " " << pairs[j].second << endl;
                    cout << "yes";
                    return 0;
                }
                else if ((pairs[i].first >= pairs[j].first &&
                         pairs[i].first < pairs[j].second) &&
                         pairs[i].second > pairs[j].second) {
                    cout << pairs[i].first << " " << pairs[i].second << " " << pairs[j].first << " " << pairs[j].second << endl;
                    cout << "yes";
                    return 0;
                }
            }
    cout << "no";
}