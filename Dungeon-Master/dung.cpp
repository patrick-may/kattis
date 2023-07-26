#include <bits/stdc++.h>

using namespace std;

typedef struct loc {
    int x;
    int y;
    int z;

    loc() {
        x = -1;
        y = -1;
        z = -1;
    }
    loc(int a, int b, int c) {
        x = a;
        y = b;
        z = c;
    }
} loc;

bool debug = true;

void tc(int l, int r, int c) {
    vector<vector<vector<char>>> tensor;
    loc start;
    loc end;

    // num layers
    for (int i = 0; i < l; ++i) {
        // rows
        vector<vector<char>> layer;
        for (int j = 0; j < r; ++j) {
            // cols
            vector<char> row(c);

            for (int k = 0; k < c; ++k) {
                cin >> row[k];
                if (row[k] == 'S') {
                    start = loc(i, j, k);
                } else if (row[k] == 'E') {
                    end = loc(i, j, k);
                }
            }

            layer.push_back(row);
        }
        tensor.push_back(layer);
    }

    if (debug) {
        for (auto l : tensor) {
            for (auto r : l) {
                for (auto c : r) {
                    cout << c;
                }
                cout << "\n";
            }
            cout << "\n";
        }

        cout << "START coords: " << start.x << " " << start.y << " " << start.z
             << "\n";
        cout << "END coords: " << end.x << " " << end.y << " " << end.z << "\n";
    }

    int mins = 0;
    // 3 dimensional bfs. nifty bruh
}
int main() {
    int l, r, c;
    while (cin >> l >> r >> c && l != 0 && r != 0 && c != 0) {
        cout << l << r << c << "\n";
        tc(l, r, c);
    }

    return 0;
}
