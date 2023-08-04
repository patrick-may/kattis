#include <bits/stdc++.h>

using namespace std;

bool debug = true;
int main() {
    int r, c;
    cin >> r >> c;
    vector<string> tab(r);
    for (int i = 0; i < r; ++i) {
        cin >> tab[i];
    }

    if (debug) cout << r << " " << c << "\n";
    int soln = 0;
    // 0 = 0th column
    vector<set<pair<char, int>>> columns(c);
    // bottom of table up until a column wouldn't match
    for (int i = r - 1; i > 0; --i) {
        ++soln;
        string currrow = tab[i];
        // bottom row up
        set<set<pair<char, int>>> currcols;

        // add current row's data to each column
        for (int j = 0; j < c; ++j) {
            columns[j].insert({currrow[j], i});
        }

        for (const auto col : columns) {
            currcols.insert(col);
        }

        if (currcols.size() != c) {
            break;
        }

        currcols.clear();
    }
    cout << soln - 1 << "\n";
    return 0;
}
