#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX(a, b) (((a)>(b))?(a):(b))

typedef struct entry {
    int initial, after, diff;
} entry;

bool sortByDiff(const entry &a, const entry &b) {
    return a.diff < b.diff;
}

int main() {
    int n, k;
    int sum = 0;
    int dishonest_sellers = 0;
    vector<entry> prices;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        entry element;
        cin >> element.initial;
        prices.push_back(element);
    }

    for (int i = 0; i < n; i++) {
        cin >> prices[i].after;
        prices[i].diff = prices[i].initial - prices[i].after;
        if (prices[i].diff < 0)
            dishonest_sellers++;
    }

    sort(prices.begin(), prices.end(), sortByDiff);
    k = MAX(k, dishonest_sellers);

    int i = 0;
    for (; i < k; i++)
        sum += prices[i].initial;
    
    for (; i < n; i++)
        sum += prices[i].after;
    
    cout << sum;
    
}