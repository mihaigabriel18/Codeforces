#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n1[19], n2[19];

bool descending(int i, int j) { return i > j; }
long long max_number_pos[19];

int* remove_index_from_arr(int* num, int len, int index) {
    int* res_num = (int *) malloc(len * sizeof(int));
    memcpy(res_num, num, len * sizeof(int));
    memcpy(res_num + index, num + index + 1, (len - index - 1) * sizeof(int));
    return res_num;
}

void solve_recursively(int* num1, int* num2, int len1, int len2, int nr_match) {

    int curr_digit_num2 = num2[0];
    // try to find digit in num1
    int index_num1 = -1;
    int index_num1_copy;
    for (int i = 0; i < len1; i++)
        if (num1[i] == curr_digit_num2) {
            index_num1 = i;
            break;
        }
    index_num1_copy = index_num1;
    int* num1_copy = (int *) malloc(len1 * sizeof(int));
    memcpy(num1_copy, num1, len1 * sizeof(int));

        sort(num1, num1 + len1, greater<int>());

        for (int i = len1 - 1; i >= -1; i--) {
            if (i == -1) {
                index_num1 = 0;
                break;
            }
            if (num1[i] >= curr_digit_num2 && num1[i] != 0) {
                if (num1[i] == curr_digit_num2 && i == len1 - 1)
                    continue;
                if (nr_match == 0 && num1[i + 1] == 0)
                    continue;
                    index_num1 = i + 1;
                break;
            }

        }

        long long res_nr = 0;
        res_nr *= 10;
        res_nr += num1[index_num1];
        for (int i = 0; i < len1; i++)
            if (i != index_num1) {
                res_nr *= 10;
                res_nr += num1[i];
            }

        long long second_num = 0;
        for (int i = 0; i < len2; i++) {
            second_num *= 10;
            second_num += num2[i];
        }
        if (res_nr <= second_num)
            max_number_pos[nr_match] = res_nr;
        else
            max_number_pos[nr_match] = -1;
    if (index_num1_copy != -1) {
        solve_recursively(remove_index_from_arr(num1_copy, len1, index_num1_copy), num2 + 1, len1 - 1, len2 - 1, nr_match + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(max_number_pos, -1, 19 * sizeof(long long));

    long long nr1, nr2;
    int length1 = 0, length2 = 0;
    cin >> nr1 >> nr2;
    int index = 18;
    while (nr1 != 0) {
        n1[index] = nr1 % 10;
        nr1 /= 10;
        index--;
        length1++;
    }
    int* num1 = n1 + index + 1;

    index = 18;
    while (nr2 != 0) {
        n2[index] = nr2 % 10;
        nr2 /= 10;
        index--;
        length2++;
    }
    int* num2 = n2 + index + 1;

    if (length1 < length2) {
        sort(num1, num1 + length1, greater<int>());
        long long result = 0;
        for (int i = 0; i < length1; i++) {
            result *= 10;
            result += num1[i];
        } 
        cout << result;
    } else {
        solve_recursively(num1, num2, length1, length2, 0);
        long long max_nr, i;
        for (i = 18; i >= 0; i--)
            if (max_number_pos[i] >= 0) {
                max_nr = max_number_pos[i];
                break;
            }
        
        long long result = 0;
        for (int j = 0; j < i; j++) {
            result *= 10;
            result += num2[j];
        }
        
        int nr_digits_max_nr = length1 - i;
        long long max_nr_copy = max_nr;

        while (nr_digits_max_nr != 0) {
            result *= 10;
            nr_digits_max_nr--;
        }

        result += max_nr;
        cout << result;
    }
}