#include <bits/stdc++.h>

#include <queue>

using namespace std;

bool debug = false;

vector<double> pq_traverse(vector<vector<pair<double, int>>>& adj_list) {
    // shamelessly ripping off this priority queue djikstra's algorithm
    // gotta practice it somehow....
    vector<bool> visited(adj_list.size(), false);
    vector<double> scaled(adj_list.size(), 0.0);
    priority_queue<pair<double, int>> pq;
    pq.push({1, 0});

    while (!pq.empty()) {
        int currnode = pq.top().second;
        double size = pq.top().first;
        pq.pop();

        if (visited[currnode]) {
            continue;
        }
        visited[currnode] = true;
        scaled[currnode] = size;

        for (auto adj_pair : adj_list[currnode]) {
            int nextnode = adj_pair.second;
            double factor = adj_pair.first;
            pq.push({factor * size, nextnode});
        }
    }
    return scaled;
}

void tc(int n, int m) {
    vector<vector<pair<double, int>>> adj_list(n);
    for (; m > 0; --m) {
        int x, y;
        double s;
        cin >> x >> y >> s;
        adj_list[x].push_back({s, y});
        adj_list[y].push_back({s, x});
    }

    if (debug) {
        int idx = 0;
        for (auto v : adj_list) {
            for (auto p : v) {
                cout << idx << " " << p.second << " " << p.first << "\n";
            }
            ++idx;
        }
    }

    vector<double> soln = pq_traverse(adj_list);

    cout << fixed;
    cout.precision(4);
    cout << soln[n - 1] << "\n";
}

int main() {
    int n, m;
    while (cin >> n and cin >> m and n != 0 and m != 0) {
        tc(n, m);
    }
    return 0;
}
