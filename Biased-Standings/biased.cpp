#include <bits/stdc++.h>

using namespace std;
bool debug = false;

void tc() {
    int n;
    cin >> n;
    vector<pair<string, int>> teams(n);
    for (int i = 0; i < n; ++i) {
        string a;
        int b;
        cin >> a >> b;
        teams[i] = {a, b};
    }

    if (debug) {
        for (auto p : teams) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    sort(teams.begin(), teams.end(),
         [](pair<string, int>& left, pair<string, int>& right) {
             return left.second < right.second;
         });

    if (debug) {
        for (auto p : teams) {
            cout << p.first << " " << p.second << "\n";
        }
    }

    long long distance = 0;
    for (int i = 0; i < n; ++i) {
        distance += abs(teams[i].second - (i + 1));
    }

    cout << distance << "\n";
}
int main() {
    int cases;
    cin >> cases;

    for (; cases > 0; --cases) {
        tc();
    }
    return 0;
}
