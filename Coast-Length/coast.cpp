#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> get_neighbors(vector<string>& land, pair<int, int> loc);

void remove_lake(vector<string>& land, pair<int, int> loc) {
    bool is =
        true;  // assume not lake, bfs until out of options or edge is found
    deque<pair<int, int>> to_visit = {loc};
    set<pair<int, int>> path = {loc};
    while (!to_visit.empty()) {
        pair<int, int> curr = to_visit.front();
        vector<pair<int, int>> neighs = get_neighbors(land, curr);
        // reached edge
        if (neighs.size() < 4) {
            is = false;
        }
        for (auto p : neighs) {
            if (land[p.first][p.second] == '0' and path.count(p) == 0) {
                to_visit.push_back(p);
            }
        }
        to_visit.pop_front();
        path.insert(curr);
    }

    if (is) {
        for (auto p : path) {
            cout << "removed lake at " << p.first << " " << p.second << "\n";
            land[p.first][p.second] = '1';
        }
    }
}

// aux fn for staying in bounds
vector<pair<int, int>> get_neighbors(vector<string>& land, pair<int, int> loc) {
    int n = land.size() - 1;
    int m = land[0].length() - 1;
    vector<pair<int, int>> adj;
    pair<int, int> p1 = {loc.first, loc.second + 1};
    pair<int, int> p2 = {loc.first, loc.second - 1};
    pair<int, int> p3 = {loc.first + 1, loc.second};
    pair<int, int> p4 = {loc.first - 1, loc.second};

    if (loc.first <= n - 1) {
        adj.push_back(p3);
    }
    if (loc.first >= 1) {
        adj.push_back(p4);
    }
    if (loc.second <= m - 1) {
        adj.push_back(p1);
    }
    if (loc.second >= 1) {
        adj.push_back(p2);
    }
    cout << "NEIGHBORS OF " << loc.first << " " << loc.second << "\n";
    for (auto p : adj) {
        cout << p.first << " " << p.second << "\n";
    }
    return adj;
}

int coast_traverse(vector<string>& land, set<pair<int, int>>& visited,
                   pair<int, int> start) {
    int coastal_land = 0;
    deque<pair<int, int>> to_visit = {start};

    while (!to_visit.empty()) {
        // get front
        pair<int, int> loc = to_visit.front();
        vector<pair<int, int>> neighs = get_neighbors(land, loc);
        coastal_land += 4 - neighs.size();  // account for borders;
        for (auto p : neighs) {
            if (visited.count(p)) {
                continue;
            }
            if (land[p.first][p.second] == '0') {
                cout << "COAST BETWEEN ( " << loc.first << ", " << loc.second
                     << ") & ( " << p.first << ", " << p.second << ")\n";
                coastal_land += 1;
            } else {
                to_visit.push_back(p);
            }
        }
        visited.insert(loc);
        to_visit.pop_front();
    }
    return coastal_land;
}

int main() {
    // read ins
    int n, m;
    cin >> n >> m;
    vector<string> land;
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        land.push_back(row);
    }

    // bfs everywhere...?
    set<pair<int, int>> visited;
    int soln = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            pair<int, int> loc = {i, j};
            // already visited this square
            if (visited.count(loc)) {
                continue;
            }

            if (land[i][j] == '1') {
                soln += coast_traverse(land, visited, loc);
            } else {
                remove_lake(land, loc);
                visited.insert({i, j});
            }
        }
    }
    cout << soln << endl;
}
