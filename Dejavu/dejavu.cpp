#include <bits/stdc++.h>

using namespace std;

int main() {
    int ct;
    cin >> ct;
    vector<pair<int, int>> points(ct);
    map<int, int> xlookup;
    map<int, int> ylookup;
    for (int i = 0; i < ct; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
        ++xlookup[x];
        ++ylookup[y];
    }

    long int soln = 0;
    for (auto p : points) {
        int currx = p.first;
        int curry = p.second;

        long xct = xlookup[currx] - 1;
        long yct = ylookup[curry] - 1;

        soln += xct * yct;
        // cout << currx << " " << curry << " " << soln << "\n";
    }

    cout << soln << "\n";
    return 0;
}
