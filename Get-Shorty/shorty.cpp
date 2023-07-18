#include <bits/stdc++.h>

using namespace std;

bool debug = false;

float traverse(map<int, vector<int>>& adj_list,
               map<pair<int, int>, float>& shrinks,
               map<pair<int, int>, float>& cache, set<int>& visited, int loc,
               float scale, int end) {
    if (loc == end - 1) {
        return scale;
    }

    float best = -1;
    for (auto next_intersection : adj_list[loc]) {
        // avoid backtracking
        if (visited.count(next_intersection)) {
            continue;
        }
        // remove option to avoid backsteps
        pair<int, int> corr(loc, next_intersection);

        float subproblem;
        if (cache.count(corr) == 1) {
            cout << "subprob";
            subproblem = cache[corr];
        } else {
            float new_scale = scale * shrinks[corr];
            visited.insert(next_intersection);
            subproblem = traverse(adj_list, shrinks, cache, visited,
                                  next_intersection, new_scale, end);
            cache[corr] = subproblem;
            cache[pair<int, int>(next_intersection, loc)] = subproblem;
            /*cout << corr.first << " " << corr.second << " " << subproblem
                 << "\n";*/
            visited.erase(next_intersection);
        }
        // cout << best << "\t" << subproblem << "\n";
        best = max(best, subproblem);
    }

    return best;
}
void tc(int n, int m) {
    map<int, vector<int>> adj_list;
    map<pair<int, int>, float> shrinks;
    for (; m > 0; --m) {
        int x, y;
        float s;
        cin >> x >> y >> s;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
        shrinks[pair<int, int>(x, y)] = s;
        shrinks[pair<int, int>(y, x)] = s;
    }

    if (debug) {
        for (auto p : adj_list) {
            cout << p.first << "\n\t";
            for (auto v : p.second) {
                cout << v << " ";
            }
            cout << "\n";
        }

        for (auto p : shrinks) {
            cout << p.first.first << " " << p.first.second << " " << p.second
                 << "\n";
        }
    }

    set<int> visited = {0};
    map<pair<int, int>, float> cache;
    cout << std::fixed << std::setprecision(4)
         << traverse(adj_list, shrinks, cache, visited, 0, 1, n) << "\n";
}

int main() {
    int n, m;
    while (cin >> n and cin >> m and n != 0 and m != 0) {
        tc(n, m);
    }
    return 0;
}
