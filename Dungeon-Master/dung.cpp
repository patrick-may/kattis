#include <bits/stdc++.h>

#include <list>
#define pb push_back

using namespace std;
// could have been done without my own custom struct... hashing locs was
// problematic and all that needed to be fixed smh
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

    bool operator<(const loc& b) const { return (x < b.x); }

    bool operator==(const loc& b) const {
        return (x == b.x && y == b.y && z == b.z);
    }
    void print() { cout << "x: " << x << " y: " << y << " z: " << z << "\n"; }

} loc;

bool debug = false;
bool debug2 = false;

vector<loc> get_neighbors(vector<vector<vector<char>>>& tensor, loc start) {
    vector<loc> adj;
    int zmax = tensor.size() - 1;
    int xmax = tensor[0].size() - 1;
    int ymax = tensor[0][0].size() - 1;
    if (debug) {
        cout << "max indexes are: " << xmax << " " << ymax << " " << zmax
             << "\n";
    }

    if (start.z <= zmax - 1 &&
        tensor[start.z + 1][start.x][start.y] != '#') {  // up
        loc n(start.x, start.y, start.z + 1);
        adj.pb(n);
    }
    if (start.z >= 1 && tensor[start.z - 1][start.x][start.y] != '#') {  // down
        loc n(start.x, start.y, start.z - 1);
        adj.pb(n);
    }
    if (start.x >= 1 &&
        tensor[start.z][start.x - 1][start.y] != '#') {  // south
        loc n(start.x - 1, start.y, start.z);
        adj.pb(n);
    }
    if (start.x <= xmax - 1 &&
        tensor[start.z][start.x + 1][start.y] != '#') {  // north
        loc n(start.x + 1, start.y, start.z);
        adj.pb(n);
    }
    if (start.y >= 1 && tensor[start.z][start.x][start.y - 1] != '#') {  // left
        loc n(start.x, start.y - 1, start.z);
        adj.pb(n);
    }
    if (start.y <= ymax - 1 &&
        tensor[start.z][start.x][start.y + 1] != '#') {  // right
        loc n(start.x, start.y + 1, start.z);
        adj.pb(n);
    }

    return adj;
}

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
                    start = loc(j, k, i);
                } else if (row[k] == 'E') {
                    end = loc(j, k, i);
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
        cout << tensor[end.z][end.x][end.y] << "\n";
    }

    int mins = 0;
    // 3 dimensional bfs. nifty bruh
    deque<pair<int, loc>> to_visit = {{0, start}};
    set<tuple<int, int, int>> visited;
    while (!to_visit.empty()) {
        pair<int, loc> f = to_visit.front();
        to_visit.pop_front();

        int dist = f.first;
        loc curr = f.second;

        if (debug) {
            curr.print();
        }
        tuple<int, int, int> hashable = {curr.x, curr.y, curr.z};
        if (visited.count(hashable)) {
            if (debug) {
                cout << "already visited:\n";
                curr.print();
            }
            continue;
        }

        if (curr == end) {
            cout << "Escaped in " << dist << " minute(s).\n";
            return;
        }

        visited.insert(hashable);

        for (auto neigh : get_neighbors(tensor, curr)) {
            if (debug) {
                cout << "\t";
                neigh.print();
            }
            to_visit.pb({dist + 1, neigh});
        }
    }
    cout << "Trapped!\n";
}
int main() {
    int l, r, c;

    while (cin >> l >> r >> c && l != 0 && r != 0 && c != 0) {
        tc(l, r, c);
    }

    return 0;
}
