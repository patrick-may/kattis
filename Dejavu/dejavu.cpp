#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct;
    cin >> ct;
    vector<pair<int, int>> points(ct);
    map<int, vector<int>> xlookup;
    map<int, vector<int>> ylookup;
    for (int i = 0; i < ct; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
        xlookup[x].push_back(y);
        ylookup[y].push_back(x);
    }

    long int soln = 0;
    for (auto p : points) {
        int currx = p.first;
        int curry = p.second;

        int xct = 0;
        for (auto xmatch : xlookup[currx]) {
            if (xmatch != curry) {
                ++xct;
            }
        }
        int yct = 0;
        for (auto ymatch : ylookup[curry]) {
            if (ymatch != currx) {
                ++yct;
            }
        }
        soln += xct * yct;
        // cout << currx << " " << curry << " " << soln << "\n";
    }

    cout << soln << "\n";
    return 0;
}
