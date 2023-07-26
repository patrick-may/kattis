#include <bits/stdc++.h>

#include <climits>

using namespace std;

bool debug = false;

int main() {
    int n;
    cin >> n;
    // read in people who live on specific street
    vector<long int> pops(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pops[i];
    }

    vector<vector<int>> intersects(n + 1);
    int m;
    cin >> m;
    for (; m > 0; --m) {
        int a, b;
        cin >> a >> b;
        intersects[a].push_back(b);
        intersects[b].push_back(a);
    }

    // debugging. problem desc. isn't great
    if (debug) {
        for (int i = 0; i < intersects.size(); ++i) {
            cout << i << "\t";
            for (auto v : intersects[i]) {
                cout << v << " ";
            }
            cout << "\n";
        }
    }

    long long minpop = LONG_LONG_MAX;
    int idx = -1;
    for (int i = 1; i <= n; ++i) {
        long long currpop = pops[i];
        for (auto neigh : intersects[i]) {
            currpop += neigh;
        }
        if (currpop < minpop) {
            idx = i;
            minpop = currpop;
        }
    }

    cout << idx << "\n";
    return 0;
}
