#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, b;
    cin >> t >> b;
    vector<int> storepacks(b);
    // ct packages per store
    for (int i = 0; i < b; ++i) {
        cin >> storepacks[i];
    }
    // most updated packages
    map<string, int> versions;
    for (int i = 0; i < t; ++i) {
        string pack;
        int ver;
        cin >> pack >> ver;
        versions[pack] = ver;
    }

    // for every store, read in their packages, diff from most updated
    for (auto store : storepacks) {
        int storesoln = 0;
        for (int i = 0; i < store; ++i) {
            string key;
            int outdated;
            cin >> key >> outdated;
            storesoln += (versions[key] - outdated);
        }
        cout << storesoln << "\n";
    }

    return 0;
}
