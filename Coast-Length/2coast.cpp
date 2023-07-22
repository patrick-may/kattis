#include <bits/stdc++.h>

using namespace std;

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
    /*cout << "NEIGHBORS OF " << loc.first << " " << loc.second << "\n";
    for (auto p : adj) {
        cout << p.first << " " << p.second << "\n";
    }*/
    return adj;
}

int coastFirstSearch(vector<string>& land, set<pair<int, int>>& visited,
                     pair<int, int> start) {
    deque<pair<int, int>> to_visit = {start};
    int coast = 0;

    while (!to_visit.empty()) {
        pair<int, int> curr = to_visit.front();
        to_visit.pop_front();
        // don't retread work
        if (visited.count(curr)) {
            continue;
        }

        vector<pair<int, int>> neighbors = get_neighbors(land, curr);
        for (auto neigh : neighbors) {
            if (land[neigh.first][neigh.second] == '1') {
                // coastline
                ++coast;
            } else {
                // adjacent water
                to_visit.push_back(neigh);
            }
        }
        visited.insert(curr);
    }
    return coast;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> graph(n);
    for (int i = 0; i < n; ++i) {
        cin >> graph[i];
    }

    int coastline = 0;
    set<pair<int, int>> visited;

    // top row
    for (int i = 0; i < m; ++i) {
        if (graph[0][i] == '1') {
            ++coastline;
        } else {
            coastline += coastFirstSearch(graph, visited, {0, i});
        }
    }
    // left side
    for (int i = 0; i < n; ++i) {
        if (graph[i][0] == '1') {
            ++coastline;
        } else {
            coastline += coastFirstSearch(graph, visited, {i, 0});
        }
    }
    // right side
    for (int i = 0; i < n; ++i) {
        if (graph[i][m - 1] == '1') {
            ++coastline;
        } else {
            coastline += coastFirstSearch(graph, visited, {i, m - 1});
        }
    }
    // bottom
    for (int i = 0; i < m; ++i) {
        if (graph[n - 1][i] == '1') {
            ++coastline;
        } else {
            coastline += coastFirstSearch(graph, visited, {n - 1, i});
        }
    }
    cout << coastline << "\n";
    return 0;
}
