#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef struct coords {
    int x, y;
} coords;

coords getCoordsForIndex(int m, int pos) {
    coords aux;
    aux.x = pos / m + 1;
    aux.y = pos % m + 1;
    return aux;
}

int getPosForCoords(int m, coords coord) {
    return (coord.x - 1) * m + (coord.y - 1);
}

coords goClockwise(int m, vector<bool> matrix, int numberOfBlocks, int pos,
                map<string, int> directions) {
    if (matrix[pos - numberOfBlocks * directions["down_left"]] == true) {
        return getCoordsForIndex(m, pos - numberOfBlocks * directions["down_left"]);
    } else if (matrix[pos - numberOfBlocks * directions["down"]]) {
        return getCoordsForIndex(m, pos - numberOfBlocks * directions["down"]);
    } else if (matrix[pos - numberOfBlocks * directions["right_down"]]) {
        
    }
}

int main() {
    int n, m, k;
    vector<coords> seats;
    vector<coords> final_seats;

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        coords aux;
        aux.x = a;
        aux.y = b;
        seats.push_back(aux);
    }

    vector<bool> matrix(n * m);

    for (int i = 0; i < matrix.size(); i++)
        matrix[i] = false;

    map<string, int> directions = {
        {"left", -1},
        {"left_up", 7},
        {"up", 8},
        {"up_right", 9},
        {"right", 1},
        {"right_down", -7},
        {"down", -8},
        {"down_left", -9}
    };

    for (int i = 0; i < k; i++) {
        coords final_coords;

        if (matrix[getPosForCoords(m, seats[i])] == false) {
            final_coords.x = seats[i].x;
            final_coords.y = seats[i].y;
        }
        else {
            
        }
    }

}